#include <string.h>
#include "stack.h"
#define MAX_SIZE 10

uint8_t check_pair(char opening,char closing);

int8_t isBalancedParanthethes(uint8_t *expression)
{
    ST_stack_t expr_stack;
    uint8_t expr_Length;
    uint8_t x,data,flag=0;
    createEmptyStack(&expr_stack);
    expr_Length=strlen(expression);
    for(x=0; x<expr_Length; x++)
    {
        if(expression[x]=='{' || expression[x]=='(')
        {
            push(&expr_stack,expression[x]);
        }
        else if(expression[x]=='}' || expression[x]==')')
        {
            getStackTop(&expr_stack,&data);
            if(isEmpty(&expr_stack) || !(check_pair(data,expression[x])))
            {
              //  printf("\n unbalance expression\n");
                return -1;
            }
            else
                pop(&expr_stack,&data);
        }
        else
            flag++;
    }
    if(flag==expr_Length)
    {
        //printf("\n Neither Parentheses is used \n");
        return -2;
    }
    if(isEmpty(&expr_stack))
    {
       // printf("\n valid expression\n");
        return 0;
    }
    else
    {
        //printf("\n unbalance expression\n");
        return -1;
    }
}

uint8_t check_pair(char opening,char closing)
{
    if(opening =='(' && closing ==')')
        return 1;
    else if(opening =='{' && closing =='}')
        return 1;
    else
        return 0;

}
