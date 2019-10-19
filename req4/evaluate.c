#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "queue.h"
static int calculator(char operation, int oper1, int oper2);

long long evaluate(char* expression)
{
    int i, len;
    long long int result = 0;
    int operand1;
    int operand2;
    char operation;

    len = expressionLength(expression);
    ST_queueInfo numbers;
    ST_queueInfo operators;

    createQueue(&numbers, len);
    createQueue(&operators, len);

    if (!checkForBalancedParantheses(expression))
    {
        printf("unbalanced expression");
        return 0;
    }
    for(i = 0; i < len; i++)
    {
        if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/' || expression[i] == '%')
        {
            enqueue(&operators, expression[i]);
        }
        else if (expression[i] >= '0' && expression[i] <= '9')
        {
            enqueue(&numbers, (expression[i]-48));
        }
    }
    dequeue(&numbers, &operand1);


    while(queue_isEmpty(&operators))
    {

        if(!queue_isEmpty(&numbers))
        {
            printf("unbalanced operation (two operators without operand in between)");
            return 0;
        }
        dequeue(&operators, &operation);
        dequeue(&numbers, &operand2);

        result= calculator((char)operation, operand1, operand2);
        operand1 = result;
    }
    if(queue_isEmpty(&numbers))
    {
        printf("unbalanced operation (two numbers without operation in between)");
    }
    return result;
}

static int calculator(char operation, int oper1, int oper2)
{
    //printf("\n%d %d %c\n", oper1, oper2, operation);
	if (operation == '+') return (oper1 + oper2);
	else if (operation == '-') return (oper1 - oper2);
	else if (operation == '*') return (oper1*oper2);
	else return (oper1 / oper2);
}

