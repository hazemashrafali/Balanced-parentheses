#include "LCS.h"
int8_t lcsGetSize(int32_t *array, uint8_t arraySize, uint8_t *sizeofLCS)
{
    uint8_t count=0,max=0,j=0,return_value;
    return_value=insertionSort(array,arraySize);
    if(return_value==0)
    {
        for(int i=0; i<arraySize; i++)
        {
            j=i+1;
            if(array[i]==array[j]-1)
                count++;
            else
            {
                if(max < count)
                {
                    max=count+1;
                    count=0;
                }
            }
        }
        *sizeofLCS=max;
        return 0;
    }
    else if(return_value==-1)
        return -1;
    else
        return -2;

}
