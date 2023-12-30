

#ifndef INC_MIDI_MIDI_H_
#define INC_MIDI_MIDI_H_

#include "song.h"

typedef struct {
	char chunk_type[4];
	uint32_t length;
	uint16_t format;
	uint16_t tracks;
	uint16_t division;
}header;

typedef struct {
	uint32_t delay;
	uint8_t note;
	uint8_t velocity;
}note;



uint8_t parse_delay (uint8_t* p_delay, uint32_t* delay);
uint8_t* get_start(uint8_t* track);

int parse_midi_event (int index, uint8_t event);
int parse_meta_event (int index);
int parse_track (uint8_t* track); //parse midi event
int parse_header (uint8_t* header);
void parse_song (uint32_t length);
void play_song (int track);

#endif
