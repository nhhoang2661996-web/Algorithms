typedef struct {
    int* data;
    int size;
    int capacity;
} Heap;


typedef struct {
    Heap maxHeap;
    Heap minHeap;
} MedianFinder;
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

MedianFinder* medianFinderCreate() {
    MedianFinder* obj = (MedianFinder*)malloc(sizeof(MedianFinder));
    
    obj->maxHeap.data = (int*)malloc(10 * sizeof(int));
    obj->maxHeap.size = 0;
    obj->maxHeap.capacity = 10; 
    
    obj->minHeap.data = (int*)malloc(10 * sizeof(int));
    obj->minHeap.size = 0;
    obj->minHeap.capacity = 10;
    
    return obj;
}
void minHeapifyUp(Heap* h,int idx){
    while (idx > 0) {
        int parent = (idx - 1) / 2; 
        
        if (h->data[idx] < h->data[parent]) {
            swap(&h->data[idx], &h->data[parent]);
            idx = parent; 
        } else {
            break; 
        }
    }
}
void maxHeapifyUp(Heap* h,int idx){
    while (idx > 0) {
        int parent = (idx - 1) / 2; 
        
        if (h->data[idx] > h->data[parent]) {
            swap(&h->data[idx], &h->data[parent]);
            idx = parent; 
        } else {
            break; 
        }
    }
}
void maxHeapifyDown(Heap* h,int idx){
    int largest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;
    if (left < h->size && h->data[left] > h->data[largest]) {
        largest = left;
    }
    if (right < h->size && h->data[right] > h->data[largest]) {
        largest = right;
    }
    if (largest != idx) {
        swap(&h->data[idx], &h->data[largest]);
        maxHeapifyDown(h,largest);   
    }
}
void minHeapifyDown(Heap* h,int idx){
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;
    if (left < h->size && h->data[left] < h->data[smallest]) {
        smallest = left;
    }
    if (right < h->size && h->data[right] < h->data[smallest]) {
        smallest = right;
    }
    if (smallest != idx) {
        swap(&h->data[idx], &h->data[smallest]);
        minHeapifyDown(h,smallest);   
    }
}
void heapPush(Heap* h, int val, int isMinHeap) {
    if (h->size >= h->capacity) {
        h->capacity *= 2; 
        h->data = (int*)realloc(h->data, h->capacity * sizeof(int));
    }
    
    h->data[h->size] = val;
    h->size++;
    
    if (isMinHeap) {
        minHeapifyUp(h, h->size - 1);
    } else {
        maxHeapifyUp(h, h->size - 1);
    }
}

int heapPop(Heap* h, int isMinHeap){
    int val = h->data[0];
    h->data[0] = h->data[h->size - 1];
    h->size--;
    if (isMinHeap) {
        minHeapifyDown(h, 0);
    }else {
        maxHeapifyDown(h, 0);
    }
    return val;
}

void medianFinderAddNum(MedianFinder* obj, int num) {
    if (obj->maxHeap.size == 0 || num <= obj->maxHeap.data[0]) {
        heapPush(&obj->maxHeap, num, 0); 
    } else {
        heapPush(&obj->minHeap, num, 1);
    }

    if (obj->maxHeap.size > obj->minHeap.size + 1) {
        int val = heapPop(&obj->maxHeap, 0); 
        heapPush(&obj->minHeap, val, 1);     
    }else if (obj->minHeap.size > obj->maxHeap.size) {
        int val = heapPop(&obj->minHeap, 1);
        heapPush(&obj->maxHeap, val, 0);
    }
}

double medianFinderFindMedian(MedianFinder* obj) {
    if (obj->maxHeap.size > obj->minHeap.size) {
        return (double)obj->maxHeap.data[0];
    }else {
        return (obj->maxHeap.data[0] + obj->minHeap.data[0]) / 2.0;
    }
}

void medianFinderFree(MedianFinder* obj) {
    if (obj == NULL) return;
    free(obj->maxHeap.data);
    free(obj->minHeap.data);
    free(obj);
}

/**
 * Your MedianFinder struct will be instantiated and called as such:
 * MedianFinder* obj = medianFinderCreate();
 * medianFinderAddNum(obj, num);
 
 * double param_2 = medianFinderFindMedian(obj);
 
 * medianFinderFree(obj);
*/