/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
 typedef struct {
    char* original_str;
    char* sorted_str;
 }newChar;
int cmpChar(const void* a, const void* b) {
    return (*(char*)a - *(char*)b);
}
int cmpNewChar(const void* a, const void* b) {
    const newChar* p1 = (const newChar*)a;
    const newChar* p2 = (const newChar*)b;
    return strcmp(p1->sorted_str, p2->sorted_str);
}
char* getSortString(char* s) {
    int len = strlen(s);
    char* str = malloc(len + 1);
    strcpy(str, s);
    qsort(str, len, sizeof(char), cmpChar);
    return str;
}
char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes) {
    newChar* sorted = malloc(strsSize * sizeof(newChar));
    
    for(int i = 0; i < strsSize; i++){
        char* sortStr = getSortString(strs[i]);
        sorted[i].original_str = strs[i];
        sorted[i].sorted_str = sortStr;
    }
    qsort(sorted, strsSize, sizeof(newChar), cmpNewChar);
    char*** result = malloc(strsSize * sizeof(char**));
    *returnColumnSizes = malloc(strsSize * sizeof(int));
    int reIdx = 0;
    int reSubIdx = 0;
    result[reIdx] = malloc(strsSize * sizeof(char*));
    for(int i = 0; i < strsSize; i++){
        if (i > 0 && strcmp(sorted[i].sorted_str, sorted[i - 1].sorted_str) != 0){
            (*returnColumnSizes)[reIdx] = reSubIdx;
            reIdx++;
            result[reIdx] = malloc(strsSize * sizeof(char*));
            reSubIdx = 0;
        }
        result[reIdx][reSubIdx++] = sorted[i].original_str;
    }
    (*returnColumnSizes)[reIdx] = reSubIdx;
    *returnSize = reIdx + 1;
    return result;
}