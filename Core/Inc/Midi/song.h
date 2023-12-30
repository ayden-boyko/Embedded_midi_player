/*
 * song.h
 *
 *  Created on: May 14, 2022
 *      Author: Bruce Herring
 *
 *  DO NOT MODIFY
 */

#ifndef INC_SONG_H_
#define INC_SONG_H_

#include <stdint.h>

// A little struct to help make tracking songs easier.
typedef struct {
	unsigned char* p_song;
	unsigned int size;
}song;

//a struct that holds the tempo and the pointer to the array
typedef struct{
	uint32_t tempo;
	unsigned char *pointer;
}tempo_info;

//a struct that holds the length of the title and the pointer to the array
typedef struct{
	int length;
	unsigned char *pointer;
}title_info;

//a struct that holds the length of the copyright and the pointer to the array
typedef struct{
	int length;
	unsigned char *pointer;
}copyright_info;


song get_song (uint8_t);
void song_info(int num);
void midi_header(int num);
void midi_track(int track);
title_info get_title(unsigned char* pointer);
copyright_info get_copyright(unsigned char* pointer);
tempo_info get_tempo(unsigned char* song);

#endif /* INC_SONG_H_ */
