/*
 * cbuffer.c
 *
 *  Created on: 3 wrz 2022
 *      Author: wojch
 */
#include <stdint.h>
#include <stddef.h>
#include "cbuffer.h"

//typedef struct cbuffer {
//	void* elements;
//	uint16_t head, tail, elemNum, maxSize;
//	size_t elemSize;
//} cbuf_t;

// initialize buffer, element size, element num
void cbuf_init(cbuf_t* b, size_t elemSize, uint16_t maxSize){
	b->elemSize = elemSize;
	b->maxSize = maxSize;
	b->elements = malloc(elemSize*b->maxSize);
	b->elemNum = 0;
	b->head = 0;
	b->tail = 0;
}
// delete buffer
void cbuf_del(cbuf_t* b){
	free(b->elements);
	free(b);
}

// isEmpty
uint8_t cbuf_isEmpty(cbuf_t* b){
	return(b->elemNum==0);
}
// isFull
uint8_t cbuf_isFull(cbuf_t* b){
	return(b->elemNum==b->maxSize);
}

// add element
uint8_t cbuf_append(cbuf_t* b, void* element){
	if(cbuf_isFull(b)) return 0;
//	b->elements[b->tail] = *element;
	memcpy(b->elements+b->tail*b->elemSize, element, b->elemSize);
	b->elemNum++;
	b->tail = (b->tail + 1) % b->maxSize;
	return 1;
}
// remove element
void* cbuf_pop(cbuf_t* b);
// overwrite element
uint8_t cbuf_ovw(cbuf_t* b, void* element){
	if(cbuf_isFull(b)){
		memcpy(b->elements+b->tail*b->elemSize, element, b->elemSize);
		b->tail = (b->tail + 1) % b->maxSize;
		b->head = (b->head + 1) % b->maxSize;
	} else{
		memcpy(b->elements+b->tail*b->elemSize, element, b->elemSize);
		b->elemNum++;
		b->tail = (b->tail + 1) % b->maxSize;
		return 1;
	}
}
// non-destructive read
void* cbuf_read(cbuf_t* b);
// non-destructive read of nth element
void* cbuf_readn(cbuf_t* b, uint16_t pos){
	pos += b->head;
	pos = pos % b->maxSize;
	return(b->elements+pos*b->elemSize);
}
