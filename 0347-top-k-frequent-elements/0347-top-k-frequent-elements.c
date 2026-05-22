/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 typedef struct {
    int value;
    int count;
} number;
int compareInts(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}
int compareNumber(const void* a, const void* b) {
    return (((number*)b)->count - ((number*)a)->count);
}
int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
    if (numsSize == 0) {
        *returnSize = 0;
        return NULL;
    }
    qsort(nums, numsSize, sizeof(int), compareInts);
    number* newNums = malloc(numsSize * sizeof(number));
    int index = 0;
    newNums[index].value = nums[0];
    newNums[index].count = 1;
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] == nums[i - 1]) {
            newNums[index].count++;
        } else {
            index++;
            newNums[index].value = nums[i];
            newNums[index].count = 1;
        }
    }
    index++;

    qsort(newNums, index, sizeof(number), compareNumber);

    int* result = (int*)malloc(k * sizeof(int));
    for (int i = 0; i < k; i++) {
        result[i] = newNums[i].value;
    }
    free(newNums);
    *returnSize = k;
    return result;
}