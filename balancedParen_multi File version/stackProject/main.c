#include "main.h"

int main()
{
    char expr[MAX_EXPR_SIZE];
    uint8_t expr_Length;
    int8_t state;
    uint8_t select;
    printf("A)run stack test code\n");
    printf("B)run check balance parentheses algorithm\n");
    printf("C)exit\n");
    select=toupper(getche());
    switch(select)
    {
    case 'A':
    {
        printf("\n");
        stackTest();
        break;
    }
    case 'B':
    {
        while(1)
        {
            printf("\nenter an expression to check:\n");
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
        break;
    }
    case 'C':
        return 0;
        break;
    default:
        printf("\nchoose (A/B) to continue:");
        break;
    }
}



