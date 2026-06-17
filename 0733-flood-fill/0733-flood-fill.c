/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** floodFill(int** image, int imageSize, int* imageColSize, int sr, int sc, int color, int* returnSize, int** returnColumnSizes) {
    *returnSize = imageSize;
    *returnColumnSizes = (int*)malloc(imageSize * sizeof(int));
    for (int i = 0; i < imageSize; i++) {
        (*returnColumnSizes)[i] = imageColSize[i];
    }
    int old = image[sr][sc];
    int colSize = imageColSize[0];
    if (old == color) return image;
    int* queue = malloc((imageSize*imageColSize[0])*sizeof(int)); 
    int front = 0;
    int rear = 0;
    int code = 50;
    int dRow[] = {-1, 1, 0, 0};
    int dCol[] = {0, 0, -1, 1};
    
    queue[rear++] = sr * code + sc;
    image[sr][sc] = color;
    while(front<rear){
        int size = rear - front;
        int row = queue[front] / code;
        int col = queue[front] % code;
        front++;
        for (int i = 0; i < 4; i++){
            int newRow = row + dRow[i];
            int newCol = col + dCol[i];
            if(newRow < 0 || newRow >= imageSize || newCol < 0 || newCol >= colSize || image[newRow][newCol] != old || image[newRow][newCol] == color) continue;
            image[newRow][newCol] = color;
            queue[rear++] = newRow * code + newCol;
        }
    }
    
    return image;
}