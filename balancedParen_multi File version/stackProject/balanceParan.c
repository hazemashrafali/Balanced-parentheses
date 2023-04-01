#include "balanceParan.h"

EN_pare_state isBalancedParanthethes(uint8_t *expression)
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
              //unbalance expression
                return unbalance;
            }
            else
                pop(&expr_stack,&data);
        }
        else
            flag++;
    }
    if(flag==expr_Length)
    {
        //Neither Parentheses is used
        return invalid;
    }
    if(isEmpty(&expr_stack))
    {
       // valid expression
        return balance;
    }
    else
    {
        //unbalance expression
        return unbalance;
    }
}

EN_state check_pair(char opening,char closing)
{
    if(opening =='(' && closing ==')')
        return TRUE;
    else if(opening =='{' && closing =='}')
        return TRUE;
    else
        return FALSE;

}
