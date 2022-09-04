/*
 * ringBuffer.h
 *
 *  Created on: 25 sie 2022
 *      Author: wojch
 */

#ifndef SRC_UTILS_RINGBUFFER_H_
#define SRC_UTILS_RINGBUFFER_H_

#include <stdint.h>

//typedef struct ringBuffer {
//		uint8_t* values;
//		uint8_t head, tail, num_entries, size;
//} RingBuffer_t;
typedef struct ringBuffer {
		int* values;
		uint16_t head, tail, num_entries, size;
		uint8_t isReady;
} RingBuffer_t;

void init_ring_buffer(RingBuffer_t* b, uint16_t maxSize);

uint8_t ring_buffer_empty(RingBuffer_t* b);

uint8_t ring_buffer_full(RingBuffer_t* b);

void ring_buffer_destroy(RingBuffer_t* b);
uint8_t add_ring_buffer(RingBuffer_t* b, int value);
//uint8_t add_ring_buffer(RingBuffer_t* b, uint8_t value);
//uint8_t remove_ring_buffer(RingBuffer_t* b);
int remove_ring_buffer(RingBuffer_t* b);

#endif /* SRC_UTILS_RINGBUFFER_H_ */
