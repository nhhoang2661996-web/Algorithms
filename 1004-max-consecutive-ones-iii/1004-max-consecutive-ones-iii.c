int longestOnes(int* nums, int numsSize, int k) {
    int count = 0;
    int left = 0;
    int maxLen = 0;
    for(int right = 0; right < numsSize ; right ++){
        if (nums[right] == 0) count++;
        if (count > k){
            if(nums[left] == 0) count--;
            left ++;
        }
        int len = right - left + 1;
        if(len > maxLen) maxLen = len;
    }
    return maxLen;
}