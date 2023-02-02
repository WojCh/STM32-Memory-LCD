/*
 * ringBuffer.c
 *
 *  Created on: 25 sie 2022
 *      Author: wojch
 */

#include "ringBuffer.h"



void init_ring_buffer(RingBuffer_t* b, uint16_t maxSize){
	b->size = maxSize;
	b->values = malloc(sizeof(int)*b->size);
	b->num_entries = 0;
	b->head = 0;
	b->tail = 0;
	b->isReady = 1;
}

uint8_t ring_buffer_empty(RingBuffer_t* b){
	return(b->num_entries==0);
}
uint8_t ring_buffer_full(RingBuffer_t* b){
	return(b->num_entries==b->size);
}
void ring_buffer_destroy(RingBuffer_t* b){
	free(b->values);
	free(b);
}
uint8_t add_ring_buffer(RingBuffer_t* b, int value){
	if(ring_buffer_full(b)) return 0;
	b->values[b->tail] = value;
	b->num_entries++;
	b->tail = (b->tail + 1) % b->size;
	return 1;
}
int remove_ring_buffer(RingBuffer_t* b){
	if(ring_buffer_empty(b)) return 0;
	int result;
	result = b->values[b->head];
	b->head = (b->head + 1) % b->size;
	b->num_entries--;
	return result;
}

uint8_t add_ovw_ring_buffer(RingBuffer_t* b, int value){
	if(ring_buffer_full(b)){
		b->values[b->tail] = value;
		b->tail = (b->tail + 1) % b->size;
		b->head = (b->head + 1) % b->size;
		return 0;
	} else{
		b->values[b->tail] = value;
		b->num_entries++;
		b->tail = (b->tail + 1) % b->size;
		return 1;
	}
}
int read_nth_ring_buffer(RingBuffer_t* b, uint16_t position){
	position += b->head;
	position = position % b->size;
	return(b->values[position]);
}
