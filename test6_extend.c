#include <stdio.h>
#include <stdlib.h>

int singleNumber(int* nums, int numsSize, int fre){
    int result = 0;
    for (int i = 0; i < 32 ; i++){
        int count = 0;
         for(int j = 0; j < numsSize; j++){
             count += (nums[j] >> i) & 0x1;   
         }   
         result |= (unsigned int)(count % fre) << i;
    }
    return result;
}

void main()
{
    int nums_5[] = {4,4,4,4,4,8,5,5,5,5,5};
    int nums_3[] = {4,4,4,3,3,3,5};
    printf("%d\n", singleNumber(nums_5, 11, 5)); 
    printf("%d\n", singleNumber(nums_3, 7, 3));
}
