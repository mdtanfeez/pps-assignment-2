#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* runningSum(int* nums, int numsSize, int* returnSize) {
    if (nums == NULL || numsSize <= 0) {
        *returnSize = 0;
        return NULL;
    }

    *returnSize = numsSize;
    int* result = (int*)malloc((size_t)numsSize * sizeof(int));
    if (result == NULL) {
        *returnSize = 0;
        return NULL;
    }

    result[0] = nums[0];
    for (int i = 1; i < numsSize; i++) {
        result[i] = result[i - 1] + nums[i];
    }

    return result;
}