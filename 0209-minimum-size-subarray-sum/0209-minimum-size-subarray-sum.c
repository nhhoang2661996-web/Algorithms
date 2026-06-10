int minSubArrayLen(int target, int* nums, int numsSize) {
    long long sum = 0;
    int left = 0;
    int minLen = numsSize + 1;
    for (int i = 0 ; i < numsSize; i ++){
        sum += nums[i];
        while (sum >= target){
            int len = i - left + 1;
            if (len < minLen) {
                minLen = len;
            }
            sum -= nums[left];
            left ++;
        }
    }
    if (minLen > numsSize) return 0;
    return minLen;
}