#include "tone.h"
#include "dac.h"
#include "midi.h"
#include "systick.h"
#include <stdint.h>
#include "printf.h"
#include "song.h"
#include "little_endian.h"
#include <string.h>

note notes[2000];
note current_note;
unsigned char* current_song;
static uint32_t tempo;
static uint32_t note_increase;
uint32_t time = 0;


//used for getiing the delay after evey midi event, using when getting not info,
uint8_t parse_delay(uint8_t* buffer, uint32_t* delay){
	int index = 0;
	uint8_t temp;
	while (buffer[index] & (1<<7)){
		temp = buffer[index] & ~(1<<7);
		*delay = (*delay << 7) + temp;
		index++;
	}
	temp = buffer[index] & ~(1<<7);
	*delay = (*delay << 7) + temp;

	return index + 1;
}

int parse_meta_event (int index){
	int length = current_song[index + 2];
	if(current_song[index + 1] == 0x51){
		index += 3;
		unsigned char t[3];
		for (int i = 0; i < length; i++){
			t[i] = current_song[index];
			index++;
		}
		tempo = convert_to_uint24(t);
	}
	else{
		index += length + 3;
	}
	return index;
}

int parse_midi_event (int index, uint8_t event){
	uint32_t delay = 0;
	if (event == 1){
		uint32_t longer = (current_song[index] & 0xff) >> 7;
		if(longer == 1){
			delay += (current_song[index] & 0x0f) << 7;
			while(longer ==1){
				++index;
				longer = (current_song[index] & 0xff) >> 7;
				if (longer == 1){
					delay += (current_song[index] & 0x0f) << 7;
				}
			}
		}
		delay += current_song[index];
		++index;
		current_note.delay = delay;
		uint8_t c_note = current_song[index];
		current_note.note = c_note;
		current_note.velocity = 0;
		notes[note_increase] = current_note;
		++note_increase;
		++index;
	}
	else{
		delay = current_song[index-1];
		++index;
		uint8_t c_note = current_song[index];
		++index;
		current_note.delay = delay;
		current_note.note = c_note;
		current_note.velocity = current_song[index];
		notes[note_increase] = current_note;
		++note_increase;
	}
	return index;
}

int parse_track (uint8_t* track){
	int length = 0;
	int first = *track;
	++track;
	int second = *track;
	int loop = 0;
	int reached = 0;
	while (loop == 0){
		first = second;
		++track;
		second = *track;
		++length;
		if (first == 114 && second == 107){
			reached = 1;
		}
		if (first == 255 && second == 47 && reached ==1){
			loop = 1;
		}
		printf("%x\n\r", *track);
	}
	printf("%x\n\r", *(++track));
	return length;
}

uint8_t* get_start (uint8_t* track){
	int first = *track;
	++track;
	int second = *track;
	int loop = 0;
	int reached = 0;
	while (loop == 0){
		first = second;
		++track;
		second = *track;
		if (first == 114 && second == 107){
			reached = 1;
		}
		if (first == 255 && second == 3 && reached == 1){
			++track;
			loop = 0;
		}
	}
	for (int i =0; i <= *track; i++){
		++track;
	}
	++track;
	return track;
}
int parse_header (uint8_t* head){

	header* songinfo = (header*) get_song(*head).p_song;

	return convert_to_uint16((uint8_t*)&songinfo->division);
}
void parse_song (uint32_t length){
	note_increase = 0;
	for (int i =0; i <=length; i++){
		if (current_song[i] == 0x4d){
			i += 3;
		}
		else if (current_song[i] == 0xff){
			int value = parse_meta_event(i);
			i = value - 1;
		}
		else{
			int k;
			switch(current_song[i] >> 4){
				case 0x9:
					k = parse_midi_event(i, 0);
					i = k;
					break;
				case 0xE:
					i += 3;
					break;
				case 0xC:
					i += 2;
					break;
				case 0xB:
					i += 3;
					break;
				case 0xD:
					i += 2;
					break;
				case 0xA:
					i += 3;
					break;
				case 0x8:
					k = parse_midi_event(i, 1);
					i = k;
			}
		}
	}
}


/* to get how long since the last note action in ticks
 500000 ms/quarter note
 divided by
 division (midi ticks)/quarter note
 then multiply the quotient by
 delay ms/midi tick
*/

void play_song (int track){
	current_song = get_song(track).p_song;
	tempo_info tempo = get_tempo(current_song);
	header* songinfo = (header*) current_song;
	char ct[5];
	strncpy(ct, songinfo->chunk_type, 4);
	ct[4]= 0;
	uint32_t division = convert_to_uint16((uint8_t*)&songinfo->division);
	int length = get_song(track).size;
	parse_song(length);
	int index = 0;
	while(index < note_increase){
		add_tone(notes[index].note, notes[index].velocity);
		//printf("note: %lu veloc: %lu delay: %lu \n\r", notes[index].note, notes[index].velocity, notes[index].delay);
		time = (tempo.tempo/ division) * notes[index].delay;
		uint32_t endtime = (*get_count() + time);
		while (*get_count() < endtime){
			play_tones();
		}
		reset();
		remove_tone(notes[index].note);
		++index;
	}
}

