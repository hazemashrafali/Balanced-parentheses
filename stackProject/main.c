#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#define MAX_SIZE 10

int main()
{
    char expr[MAX_SIZE];
    uint8_t expr_Length;
    int8_t state;
    while(1)
    {
    printf("enter an expression to check:\n");
    gets(expr);
    state=isBalancedParanthethes(expr);
    switch(state)
    {
    case 0:
        printf("\n valid expression\n");
        break;
    case -1:
        printf("\n unbalance expression\n");
        break;
    case -2:
        printf("\n Neither Parentheses is used \n");
        break;
    default:
        printf("error!");
        break;
    }
    }
}



