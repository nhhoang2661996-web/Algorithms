/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    int left = 0;
    int right = numbersSize-1;
    int sum = 0;
    *returnSize = 2;
    int* result = malloc(2*sizeof(int));
    while(left < right){
        sum = numbers[left] + numbers[right];
        if (sum == target) {
            break; 
        }else if (sum > target) {
            right--; 
        }else {
            left++; 
        }
    }
    result[0] = left + 1;
    result[1] = right + 1;
    return result;
}