#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


typedef struct stack {
uint8_t elements[STACK_SIZE];
uint8_t top;
}ST_stack_t; // Type


void createEmptyStack(ST_stack_t *stack)
{
    for(int x=0; x<STACK_SIZE; x++)
        stack->elements[x]=0;
    stack->top=-1;
}

uint8_t push(ST_stack_t *stack, uint8_t data)
{
    if(stack->top == STACK_SIZE)  //check stack is full
        return -1;
    stack->elements[stack->top]=data;
    stack->top++;
    return 0;
}

uint8_t pop(ST_stack_t *stack, uint8_t *data)
{
    if(stack->top == -1)
        return -2;      //check stack is empty
    *data=stack->elements[stack->top];
    stack->top--;
    return 0;
}

uint8_t printStack(ST_stack_t *stack)
{
    if(stack->top == STACK_SIZE)  //check stack is full
        return -1;
    if(stack->top == -1)
        return -2;      //check stack is empty
    for(int x=0; x<STACK_SIZE; x++)
        printf("%c\n",stack->elements[x]);
    return 0;
}

uint8_t getStackTop(ST_stack_t *stack, uint8_t *topData)
{
    if(stack->top == -1)
        return -2;      //check stack is empty
    *topData=stack->elements[stack->top];
    return 0;
}

uint8_t isFull(ST_stack_t *stack)
{
    if(stack->top == STACK_SIZE)  //check stack is full
        return -1;
    else
        return 0;
}

uint8_t isEmpty(ST_stack_t *stack)
{
    if(stack->top == -1)
        return -2;      //check stack is empty
    else
        return 0;
}
