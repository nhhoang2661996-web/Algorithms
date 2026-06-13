void swap (int* a, int* b ){
    int n = *a;
    *a = *b;
    *b = n ;
}
void swiftDown(int* heap, int heapSize,int index){
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int smallest = index;
    if(right < heapSize &&heap[smallest] > heap[right])smallest = right;
    if(left < heapSize &&heap[smallest] > heap[left])smallest = left;
    if(smallest != index){
        swap(&heap[index],&heap[smallest]);
        swiftDown(heap,heapSize,smallest);
    }
}
void swiftUp(int* heap, int index) {
    if (index == 0) return;
    int parent = (index - 1)/2;
    if (heap[index] < heap[parent]) {
        swap(&heap[index],&heap[parent]);
        swiftUp(heap, parent);
    }
}
int findKthLargest(int* nums, int numsSize, int k) {
    int minHeap[k];
    for(int i = 0; i< numsSize; i ++){
        if (i < k){
            minHeap[i] = nums[i];
            swiftUp(minHeap,i);
        }else  if (minHeap[0] < nums[i]){
            minHeap[0] = nums[i];
            swiftDown(minHeap,k,0);
        }
    }
    return minHeap[0];
}