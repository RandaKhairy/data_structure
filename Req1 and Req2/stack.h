/*
 * stack.h
 *
 *  Created on: Oct 18, 2019
 *      Author: Randa
 */

#ifndef STACK_H_
#define STACK_H_

#include <stdlib.h>

typedef struct
{
	int top;
	int size;
	int* stackPtr;
}ST_stackInfo;

typedef enum {False, True} bool;

/*
 * Function: createStack
 * arguments: info => pointer to ST_stackInfo struct that holds the stack informations
 * 			  size => the stack required size
 * Description: function that creates a new stack and initialize its top value with -1, size with the input size
 * and allocate a new location in the heap and store it address in the stackPtr
 * */
void createStack(ST_stackInfo* info, int size);

/*
 * Function: push
 * arguments: info => pointer to ST_stackInfo struct that holds the stack informations
 * 			  data => the data to be pushed into the stack
 * Description: function that add new data in an existing stack and then increment the top value to the next empty place.
 */
void push(ST_stackInfo* info, int data);

/*
 * Function: pop
 * arguments: info => pointer to ST_stackInfo struct that holds the stack informations
 * 			  data => pointer to a variable to store the poped data in it.
 * Description: function that return the last data pushed into the stack,
 * then decrement the top value.
 */
void pop(ST_stackInfo* info, int* data);

/*
 * Function: expressionLength
 * arguments: expression => pointer to char that holds a string.
 * Description: function that returns the length of the input string.
 */
unsigned char expressionLength(char* expression);

/*
 * Function: isEmpty
 * arguments: info => pointer to ST_stackInfo.
 * Description: function that returns if the stack is empty or not.
 */
unsigned char isEmpty(ST_stackInfo* info);

/*
 * Function: checkForBalancedParantheses
 * arguments: info => pointer to char that holds a string that contains parentheses.
 * Description: function that returns if the parentheses in the input string are balanced or not.
 */
unsigned char checkForBalancedParantheses(char* expression);

#endif /* STACK_H_ */
