/*
 * stack.c
 *
 *  Created on: Oct 18, 2019
 *      Author: Randa
 */

#include "stack.h"

void createStack(ST_stackInfo *info, int size)
{
	info->top = -1;
	info->size = size;
	int* st = (int*) malloc(sizeof(int)*size);
	info->stackPtr = st;
}

void push(ST_stackInfo* info, int data)
{
	if((info->top) != ((info->size) - 1))	/*check if the stack is full*/
	{
		info->top++;
		info->stackPtr[info->top] = data;
	}
}

void pop(ST_stackInfo *info, int* data)
{
	if((info->top) != -1)		/*check if the stack is empty*/
	{
		*data = info->stackPtr[info->top];
		info->top--;
	}
}

unsigned char expressionLength(char* expression)
{
	unsigned char length = 0;
	while(expression[length] != '\0')
	{
		length++;
	}
	return length;
}

unsigned char isEmpty(ST_stackInfo* info)
{
	unsigned char empty;
	if(info->top == -1)
	{
		empty = True;
	}
	else
	{
		empty = False;
	}
	return empty;
}

unsigned char checkForBalancedParantheses(char* expression)
{

	unsigned char i = 0;
	int data = 0;
	unsigned char balanced = True;

	ST_stackInfo st;
	unsigned char stackSize = expressionLength(expression);
	createStack(&st, stackSize);

	while(expression[i] != '\0')
	{
		if(expression[i] == '(' || expression[i] == '[' || expression[i] == '{')
		{
			push(&st, expression[i]);
		}
		else
		{
			switch (expression[i])
			{
			case ')':
				pop(&st, &data);
				if((data == '[') | (data == '{'))
				{
					return False;
				}
			break;
			case ']':
				pop(&st, &data);
				if((data == '(') | (data == '{'))
				{
					return False;
				}
			break;
			case '}':
				pop(&st, &data);
				if((data == '[') | (data == '('))
				{
					return False;
				}
			break;
			}
		}
		i++;
	}
	if(isEmpty(&st))
	{
		balanced = True;
	}
	else
	{
		balanced = False;
	}
	return balanced;
}

