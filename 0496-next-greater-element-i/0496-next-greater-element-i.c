/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    *returnSize = nums1Size;
    int map[10001];
    int* result = malloc(nums1Size * sizeof(int));
    for (int i = 0;i < 10001;i++) map[i] = -1;
    int* stack = malloc(nums2Size * sizeof(int));
    int top = -1;
    for(int i = 0;i < nums2Size;i++){
        while (top >= 0&&nums2[i] > stack[top]) {
            map[stack[top]] = nums2[i];
            top--;
        }
        stack[++top] = nums2[i];
    }
    for (int i = 0;i < nums1Size;i++) {
        result[i] = map[nums1[i]];
    }
    return result;
}