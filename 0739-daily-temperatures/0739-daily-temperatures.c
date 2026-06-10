/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize) {
    int* answer = calloc(temperaturesSize, sizeof(int));
    *returnSize = temperaturesSize;
    int* stack = malloc(temperaturesSize * sizeof(int));;
    int top = 0;
    for(int i = 0 ; i < temperaturesSize ; i++){
        while(top > 0 && temperatures[stack[top - 1]] < temperatures[i]){
            int prevIndex = stack[top - 1];
            answer[prevIndex] = i - prevIndex;
            top--;
        }
        stack[top++] = i;
    }
    return answer;
}