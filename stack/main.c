#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main()
{

    uint8_t text[5]= {'a','b','c','d','e'};
    uint8_t data,top_data;
    ST_stack_t newStack;
    createEmptyStack(&newStack);        //create an empty stack
    for(int x=0;x<5;x++)
        push(&newStack,text[x]);        //push 5 characters to the stack
    printStack(&newStack);              //print all stack data
    pop(&newStack,&data);               //pop one character
    getStackTop(&newStack,&top_data);
    printf("stack top:%c\n",top_data);  //print the stack top
    printStack(&newStack);              //print all stack data


}

