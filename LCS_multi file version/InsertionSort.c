#include "InsertionSort.h"

int8_t insertionSort(int32_t *array, uint8_t arraySize)
{
    uint8_t key,x,y;
    int32_t temp;
    if(arraySize == 0)
        return -1;  //the array is empty
    if(arraySize < 0 || arraySize >10)
        return -2;  //if the array size is 0 or >10
    for(x=1; x<arraySize; x++)
    {
        y=x;
        while(array[y] < array[y-1] && y > 0)
        {
            temp=array[y];
            array[y]=array[y-1];
            array[y-1]=temp;
            y--;
        }
    }
    return 0;       //sorting is done without errors
}

void printArray(int32_t *array, uint8_t arraySize)
{
    for(int x=0 ; x<arraySize; x++)
    {
        printf("%d ",array[x]);
    }
    printf("\n");
}
