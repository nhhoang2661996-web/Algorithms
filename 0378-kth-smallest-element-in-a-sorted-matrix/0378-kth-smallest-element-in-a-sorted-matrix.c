typedef struct {
    int val;
    int r;
    int c;
} HeapNode;
void setNode(HeapNode* node, int val, int r, int c) {
    node->val = val;
    node->r = r;
    node->c = c;
}
void swap(HeapNode* a, HeapNode* b) {
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}
void shiftDown(HeapNode* heap, int heapSize, int i) {
    int minIndex = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < heapSize && heap[left].val < heap[minIndex].val) minIndex = left;
    if (right < heapSize && heap[right].val < heap[minIndex].val) minIndex = right;

    if (i != minIndex) {
        swap(&heap[i], &heap[minIndex]);
        shiftDown(heap, heapSize, minIndex);
    }
}
void shiftUp(HeapNode* heap, int i) {
    while (i > 0 && heap[(i - 1) / 2].val > heap[i].val) {
        swap(&heap[(i - 1) / 2], &heap[i]);
        i = (i - 1) / 2;
    }
}
int kthSmallest(int** matrix, int matrixSize, int* matrixColSize, int k) {
    int n = matrixSize;
    HeapNode* heap = (HeapNode*)malloc(sizeof(HeapNode) * n);
    int heapSize = 0;

    for (int i = 0; i < n; i++) {
        setNode(&heap[heapSize], matrix[i][0], i, 0);
        shiftUp(heap, heapSize);
        heapSize++;
    }

    for (int i = 0; i < k - 1; i++) {
        HeapNode root = heap[0];

        if (root.c + 1 < n) {
            heap[0].val = matrix[root.r][root.c + 1];
            heap[0].r = root.r;
            heap[0].c = root.c + 1;
        } else {
            heap[0] = heap[heapSize - 1];
            heapSize--;
        }
        shiftDown(heap, heapSize, 0);
    }

    int result = heap[0].val;
    free(heap);
    return result;
}