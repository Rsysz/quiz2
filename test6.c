int singleNumber(int *nums, int numsSize)
{
    int lower = 0, higher = 0;
    for (int i = 0; i < numsSize; i++) {
        int next_lower = lower ^ nums[i] & ~higher;
        higher = (~nums[i] & higher & ~lower)|(nums[i] & ~higher & lower);
        lower = next_lower;
    }
    return lower;
} 
