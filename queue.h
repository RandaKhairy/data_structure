/*
 * queue.h
 *
 *  Created on: Oct 19, 2019
 *      Author: Mohammed Nassar
 */

#ifndef QUEUE_H_
#define QUEUE_H_

#include <stdlib.h>


typedef unsigned char uint8;
typedef signed char sint8;

typedef unsigned short uint16;
typedef signed short sint16;

typedef unsigned long uint32;
typedef signed long sint32;

typedef unsigned long uint64;
typedef signed long sint64;

//#define NULL (void*)0

typedef struct
{
	sint8 first;
	sint8 last;
	uint16 size;
	uint16 maxSize;
	uint16* queuePtr;
}ST_queueInfo;


/*
 * Function: createQueue
 * arguments: info => pointer to ST_queueInfo struct that holds the queue informations
 * 			  size => the queue required size
 * Description: function that creates a new queue and initialize its top value with -1, size with the input size
 * and allocate a new location in the heap and store it address in the queuePtr
 * */
extern void createQueue(ST_queueInfo* info, uint16 maxSize);
/*
 * Function: enqueue
 * arguments: info => pointer to ST_queueInfo struct that holds the queue informations
 * 			  data => the data to be Enqueued into the queue
 * Description: function that add new data in an existing queue and then increment the top value to the next empty place.
 */
extern void enqueue(ST_queueInfo* info, uint16 data);
/*
 * Function: dequeue
 * arguments: info => pointer to ST_queueInfo struct that holds the queue informations
 * 			  data => pointer to a variable to store the Dequeued data in it.
 * Description: function that return the First data Enqueued into the queue,
 * then decrement the top value.
 */
extern void dequeue(ST_queueInfo* info, uint16* data);
extern uint8 expressionLength(char* expression);


#endif /* QUEUE_H_ */
