/*
 * main.c
 *
 *  Created on: Oct 18, 2019
 *      Author: Randa
 */
#include <stdio.h>
#include "stack.h"


int main(void)
{
	unsigned char balanced;
	char* exp = "[(1+2)+[3]]{";
	balanced = checkForBalancedParantheses(exp);
	if(balanced == True)
	{
		printf("Balanced\n");
	}
	else
	{
		printf("Unbalanced\n");
	}
	return 0;
}

