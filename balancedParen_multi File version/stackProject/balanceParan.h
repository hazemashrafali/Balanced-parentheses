#ifndef BALANCEPARAN_H_INCLUDED
#define BALANCEPARAN_H_INCLUDED

/*<<<<<< header inclusion >>>>>>*/
#include <string.h>
#include "stack.h"

/*<<<<<< Macro definition >>>>>>*/
#define MAX_SIZE 10

/*<<<<<< type definition >>>>>>*/
typedef enum EN_pare_state{
    balance=0,unbalance=-1,invalid=-2
}EN_pare_state;

typedef enum EN_state
{
    FALSE,TRUE
}EN_state;
/*<<<<<< function prototype >>>>>>*/
EN_pare_state isBalancedParanthethes(uint8_t *expression);
EN_state check_pair(char opening,char closing);


#endif // BALANCEPARAN_H_INCLUDED
