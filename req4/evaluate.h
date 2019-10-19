#ifndef __QUE__
#define __QUE__

#include"stack.h"
#include "queue.h"

/*
 * Function:  evaluate
 * --------------------
 * computes a mathematical expression using stack to check balancing and Queues to evaluate it sequentially:
 *
 * expression: array of characters contains numbers and operators
 *
 * returns: the result of the expression
 *
 * restrictions : no precedence and the number should from 0 to 9
 */
long long evaluate(char* expression);

#endif // __LINKED_LIST__
