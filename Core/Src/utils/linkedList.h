/*
 * linkedList.h
 *
 *  Created on: 3 gru 2022
 *      Author: wojch
 */

#ifndef SRC_UTILS_LINKEDLIST_H_
#define SRC_UTILS_LINKEDLIST_H_

#include<stdio.h>
#include<stdlib.h>

/* A linked list node */
struct Node
{
// Any data type can be stored in this node
void  *data;
struct Node *next;
};

/* Function to add a node at the beginning of Linked List.
   This function expects a pointer to the data to be added
   and size of the data type */
void push(struct Node** head_ref, void *new_data, size_t data_size)
{
// Allocate memory for node
struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

new_node->data  = malloc(data_size);
new_node->next = (*head_ref);

// Copy contents of new_data to newly allocated memory.
// Assumption: char takes 1 byte.
int i;
for (i=0; i<data_size; i++)
*(char *)(new_node->data + i) = *(char *)(new_data + i);

// Change head pointer as new node is added at the beginning
(*head_ref)    = new_node;
}

#endif /* SRC_UTILS_LINKEDLIST_H_ */
