/*
 * queue.c
 *
 *  Created on: Oct 19, 2019
 *      Author: Mohammed Nassar
 */
#include <stdio.h>
#include "queue.h"


void createQueue(ST_queueInfo* info, int maxSize)
{
	info->first = -1 ;
	info->last  = -1 ;
	info->size  = 0 ;
	info->maxSize = maxSize;
	int* qu = (int*) malloc(sizeof(int)*maxSize);
	info->queuePtr = qu;
}

void enqueue(ST_queueInfo* info, int data)
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

void dequeue(ST_queueInfo* info, int* data)
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



int queue_isEmpty(ST_queueInfo* info)
{
	if( (info->size) != 0 )
		{
		//printf("\nqueue is not Empty\n");
          return 1;
		}
		else
		{
			//printf("\nqueue is Empty\n");
			return 0;
		}
}
