/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
 typedef struct {
    int r;
    int c;
} Point;
int** updateMatrix(int** mat, int matSize, int* matColSize, int* returnSize, int** returnColumnSizes) {
    int cols = matColSize[0];
    Point* queue = malloc(matSize * cols * sizeof(Point));
    int front = 0;
    int rear = 0;
    int distance = 1;
    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};
    for(int i =0; i<matSize;i++){
        for(int j =0; j<cols;j++){
            if(mat[i][j] == 0) queue[rear++] = (Point){i,j};
            else if(mat[i][j] == 1) mat[i][j] = -1;
        }
    }
    while (front < rear) {
        int currSize = rear - front;
        for(int i = 0; i < currSize; i ++){
            Point curr = queue[front++];
            for (int j = 0; j < 4; j++) {
                int nr = curr.r + dr[j];
                int nc = curr.c + dc[j];
                if (nr >= 0 && nr < matSize && nc >= 0 && nc < cols && mat[nr][nc] == -1) {
                    mat[nr][nc] = distance;
                    queue[rear++] = (Point){nr, nc};
                }
            }
        }
        distance++;
    }
    *returnSize = matSize;
    *returnColumnSizes = malloc(matSize * sizeof(int));
    for(int i =0; i < matSize ; i++){
        (*returnColumnSizes)[i] = cols;
    }
    
    return mat;
}