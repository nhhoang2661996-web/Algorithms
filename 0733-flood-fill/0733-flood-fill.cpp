class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int old = image[sr][sc];
        if (old == color) return image;
        queue<pair<int, int>> q;
        q.push(make_pair(sr, sc));
        image[sr][sc] = color;
        int dRow[] = {-1, 1, 0, 0};
        int dCol[] = {0, 0, -1, 1};
        while (!q.empty()) {
            pair<int, int> curr = q.front();
            q.pop();
            int row = curr.first;
            int col = curr.second;
            for (int i = 0; i < 4 ; i++){
                int newRow = row + dRow[i];
                int newCol = col + dCol[i];
                if(newRow < 0 || newRow >= image.size() || newCol < 0 || newCol >= image[0].size() || image[newRow][newCol] != old || image[newRow][newCol] == color) continue;
                image[newRow][newCol] = color;
                q.push(make_pair(newRow, newCol));
            }
        }
        return image;
    }
};