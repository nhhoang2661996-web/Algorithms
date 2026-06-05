/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 #define SIZE  10000
 typedef struct {
    int key;   
    int value;
} hashEntry;
hashEntry hashMap[SIZE];
 int hash (int key){
    int id = key % SIZE;
    if (id < 0) {
        id += SIZE;
    }
    return id;
 }
 void insert(int key, int value) {
    int id = hash(key);
    
    while (hashMap[id].value != -1) {
        id = (id + 1) % SIZE;
    }
    
    hashMap[id].key = key;
    hashMap[id].value = value;
}
 
 int search(int key) {
    int id = hash(key);
    
    while (hashMap[id].value != -1) {
        if (hashMap[id].key == key) {
            return hashMap[id].value;
        }
        id = (id + 1) % SIZE; 
    }
    return -1; 
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    for (int i = 0; i < SIZE; i++) hashMap[i].value = -1;
    for (int i = 0; i < numsSize; i++) {
        int n = target - nums[i];
        int found = search(n);
        if (found != -1){
            int* result = malloc(2*sizeof(int));
            *returnSize = 2;
            result[0] = found;
            result[1] = i;
            return result;
        }
        insert(nums[i],i);
    }
    
    *returnSize = 0;
    return NULL;
}