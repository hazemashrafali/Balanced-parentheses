#include "stack.h"

void createEmptyStack(ST_stack_t *stack)
{
    for(int x=0; x<STACK_SIZE; x++)
        stack->elements[x]=0;
    stack->top=-1;
}

int8_t push(ST_stack_t *stack, uint8_t data)
{
    if(stack->top == (STACK_SIZE-1))  //check stack is full
        return -1;
    stack->top++;
    stack->elements[stack->top]=data;
    return 0;
}

int8_t pop(ST_stack_t *stack, uint8_t *data)
{
    if(stack->top == -1)
        return -2;      //check stack is empty
    *data=stack->elements[stack->top];
    stack->top--;
    return 0;
}

int8_t printStack(ST_stack_t *stack)
{
    if(stack->top == -1)
        return -2;      //check stack is empty
    for(int x=stack->top; x>-1; x--)
        printf("%c\n",stack->elements[x]);
    if(stack->top == (STACK_SIZE-1))  //check stack is full
        return -1;
    else
        return 0;
}

int8_t getStackTop(ST_stack_t *stack, uint8_t *topData)
{
    *topData=stack->elements[stack->top];
    if(stack->top == -1)
        return -2;      //check stack is empty
    else
        return 0;
}

int8_t isFull(ST_stack_t *stack)
{
    if(stack->top == (STACK_SIZE-1))  //check stack is full
        return -1;
    else
        return 0;
}

int8_t isEmpty(ST_stack_t *stack)
{
    if(stack->top == -1)
        return -2;      //check stack is empty
    else
        return 0;
}


void stackTest()
{
    uint8_t text[5]= {'a','b','c','d','e'};
    uint8_t text_2[7]= {'q','w','e','r','t','y','u'};
    uint8_t data,top_data;
    ST_stack_t newStack;
    createEmptyStack(&newStack);        //create an empty stack
    for(int x=0; x<5; x++)
        printf("push state=%d\n",push(&newStack,text[x]));         //push 5 characters to the stack
    printStack(&newStack);              //print all stack data
    pop(&newStack,&data);               //pop one character
    getStackTop(&newStack,&top_data);
    printf("stack top:%c\n",top_data);  //print the stack top
    printStack(&newStack);              //print all stack data
    for(int x=0; x<7; x++)
    {
        if(isFull(&newStack) != -1 )     //check stack is full
            printf("push state=%d\n",push(&newStack,text_2[x]));      //Push another 7 different characters to the stack
        else
        {
            printf("====the stack is full=====\n");
            break;
        }
    }
    getStackTop(&newStack,&top_data);
    printf("stack top:%c\n",top_data);  //print the stack top
    printStack(&newStack);              //print all stack data
    for(int x=0; x<4; x++)
        pop(&newStack,&data);           // Pop 4 characters from the stack
    getStackTop(&newStack,&top_data);
    printf("stack top:%c\n",top_data);  //print the stack top
    printStack(&newStack);              //print all stack data
    for(int x=0; x<7; x++)
    {
        if(isEmpty(&newStack) != -2)    //check stack is empty
            printf("pop state=%d\n",pop(&newStack,&data));// Pop 7 characters from the stack
        else
        {
            printf("====the stack is empty=====\n");
            break;
        }
    }
    getStackTop(&newStack,&top_data);
    printf("stack top:%c\n",top_data);  //print the stack top

    if(isEmpty(&newStack) == -2)
        printf("====the stack is empty=====\n");            //print all stack data
    else
        printStack(&newStack);
    while(1);
}
