void dfs(char** grid, int gridSize, int gridColSize, int r, int c){
    if (r < 0 || r >= gridSize || c < 0 || c >= gridColSize || grid[r][c] == '0') return;
    
    grid[r][c] = '0';

    dfs(grid, gridSize, gridColSize, r - 1, c);
    dfs(grid, gridSize, gridColSize, r + 1, c);
    dfs(grid, gridSize, gridColSize, r , c - 1);
    dfs(grid, gridSize, gridColSize, r, c + 1);
}
int numIslands(char** grid, int gridSize, int* gridColSize) {
    int count = 0;
    int colSize = gridColSize[0];
    for(int i = 0; i < gridSize; i ++){
        for(int j = 0; j < colSize; j ++){
            if(grid[i][j] == '1'){
                dfs(grid,gridSize,colSize,i,j);
                count++;
            }
        }
    }
    return count;
}