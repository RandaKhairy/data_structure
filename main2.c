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
		uint16 data;
		uint16 assign;
        char* exp = "[(1+2)+[3]]{";
		
		ST_queueInfo numbers;
		ST_queueInfo calc;

		uint16 queueSize = expressionLength(exp);


		createQueue(&numbers, queueSize);
		createQueue(&calc, queueSize);
	
	uint8 l=0;

	printf("Numbers = ");

	while(l<=queueSize)
		{
			if ( (exp[l] >= '0') && (exp[l] <= '9') )
			{
				enqueue(&numbers, exp[l]);
			}
			l++;
		}



		while( ( numbers.size) != 0 )
				{
					dequeue(&numbers, &data);
					printf("%c ",data);
				}


	printf("\n");
	printf("calculations = ");
	l=0;
		while(l<=queueSize)
				{
					if ( (exp[l] == '+') || (exp[l] == '-') || (exp[l] == '/') || (exp[l] == '*') )
					{
						enqueue(&calc, exp[l]);
					}
					l++;
				}


				while( ( calc.size) != 0 )
						{
							dequeue(&calc, &assign);
							printf("%c ",assign);
						}

	return 0;
}

