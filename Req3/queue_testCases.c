/*
 * main.c
 *
 *  Created on: Oct 18, 2019
 *      Author: Mohammed Nassar
 */
#include <stdio.h>
#include "queue.h"

int main(void)
{
	//uint8 i = 0;
	    sint16 data;
		uint16 assign;
        char* exp = "[(1+2)+[3]]{";
		
		ST_queueInfo numbers;
		ST_queueInfo operators;

		uint16 queueSize = expressionLength(exp);


		createQueue(&numbers, queueSize);
		createQueue(&operators, queueSize);
	
	uint8 l=0;



	while(l<=queueSize)
		{
			if ( (exp[l] >= '0') && (exp[l] <= '9') )
			{
				enqueue(&numbers, exp[l]);
			}
			l++;
		}

	queue_isEmpty(&numbers);
	printf("numbers = ");
		while( ( numbers.size) != 0 )
				{
					dequeue(&numbers, &data);
					printf("%c ",data);
				}

		queue_isEmpty(&numbers);

	printf("\n");
	printf("operators = ");
	l=0;
		while(l<=queueSize)
				{
					if ( (exp[l] == '+') || (exp[l] == '-') || (exp[l] == '/') || (exp[l] == '*') )
					{
						enqueue(&operators, exp[l]);
					}
					l++;
				}


				while( ( operators.size) != 0 )
						{
							dequeue(&operators, &assign);
							printf("%c ",assign);
						}

	return 0;
}

