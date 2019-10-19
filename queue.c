/*
 * queue.c
 *
 *  Created on: Oct 19, 2019
 *      Author: Mohammed Nassar
 */
#include <stdio.h>
#include "queue.h"

uint8 expressionLength(char* expression)
{
	unsigned char length = 0;
	while(expression[length] != '\0')
	{
		length++;
	}
	return length;
}

void createQueue(ST_queueInfo* info, uint16 maxSize)
{
	info->first = -1 ;
	info->last  = -1 ;
	info->size  = 0 ;
	info->maxSize = maxSize;
	uint16* qu = (uint16*) malloc(sizeof(uint16)*maxSize);
	info->queuePtr = qu;
}

void enqueue(ST_queueInfo* info, uint16 data)
{
	if( (info->size) != (info->maxSize) )	/*check if the queue is full*/
		{
			if( (info->size) == 0 ) /*check if the queue is full*/
			{
			info->first++;
			}
			info->last++;
			info->size++;
			info->queuePtr[info->last] = data;
		}
}

void dequeue(ST_queueInfo* info, uint16* data)
{
		if( ( (info->first) != (info->last) ) ||  ( (info->size) != 0 )    )		/*check if the queue is empty*/
		{
			*data = info->queuePtr[info->first];
			info->first++;
			info->size--;
		}
		else if ( ((info->first) == (info->last)) && (info->last) != -1 )
		{
			info->first =-1;
			info->last  =-1;
		}

}
