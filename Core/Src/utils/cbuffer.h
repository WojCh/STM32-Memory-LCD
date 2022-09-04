/*
 * cbuffer.h
 *
 *  Created on: 2 wrz 2022
 *      Author: wojch
 */

#ifndef SRC_UTILS_CBUFFER_H_
#define SRC_UTILS_CBUFFER_H_

//typedef struct cbuffer cbuf_t;
typedef struct cbuffer {
	void* elements;
	uint16_t head, tail, elemNum, maxSize;
	size_t elemSize;
	uint8_t isReady;
} cbuf_t;



// initialize buffer, element size, element num
void cbuf_init(cbuf_t* b, size_t elementSize, uint16_t elemNum);
// delete buffer
void cbuf_del(cbuf_t* b);

// isEmpty
uint8_t cbuf_isEmpty(cbuf_t* b);
// isFull
uint8_t cbuf_isFull(cbuf_t* b);

// add element
uint8_t cbuf_append(cbuf_t* b, void* element);
// remove element
void* cbuf_pop(cbuf_t* b);
// overwrite element
uint8_t cbuf_ovw(cbuf_t* b, void* element);
// non-destructive read
void* cbuf_read(cbuf_t* b);
// non-destructive read of nth element
void* cbuf_readn(cbuf_t* b, uint16_t);

#endif /* SRC_UTILS_CBUFFER_H_ */
