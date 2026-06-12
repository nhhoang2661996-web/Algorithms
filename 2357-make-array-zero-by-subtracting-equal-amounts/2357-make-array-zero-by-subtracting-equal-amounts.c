int minimumOperations(int* nums, int numsSize) {
    int arrCheck[101] = {0};
    int result = 0;
    for(int i = 0; i < numsSize; i++){
        if(nums[i] > arrCheck[nums[i]]){
            arrCheck[nums[i]] = nums[i];
            result++;
        }
    }
    return result;
}