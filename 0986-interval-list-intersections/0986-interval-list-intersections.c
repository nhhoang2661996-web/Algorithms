/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int min(int x, int y){
    return (x > y) ? y : x;
}
int max(int x, int y){
    return (x > y) ? x : y;
}  

int** intervalIntersection(int** firstList, int firstListSize, int* firstListColSize, int** secondList, int secondListSize, int* secondListColSize, int* returnSize, int** returnColumnSizes) {
    int maxSize = firstListSize + secondListSize;
    int** result = (int**)malloc(maxSize * sizeof(int*));
    int count = 0;

    int i = 0;
    int j = 0;

    while(i < firstListSize && j < secondListSize){
        int start = max(firstList[i][0],secondList[j][0]);
        int end = min(firstList[i][1],secondList[j][1]);

        if (start <= end){
            result[count] = (int*)malloc(2 * sizeof(int));
            result[count][0] = start;
            result[count][1] = end;
            count++;
        }

        if (firstList[i][1] < secondList[j][1]) {
            i++;
        } else {
            j++;
        }
    }

    if (count == 0){
        *returnSize = 0;
        *returnColumnSizes = NULL;
        free(result);
        return NULL;
    }else {
        *returnSize = count;
        *returnColumnSizes = (int*)malloc(count * sizeof(int));
        for (int n = 0; n < count; n++) {
            (*returnColumnSizes)[n] = 2; 
        }
    }
    return result;
}