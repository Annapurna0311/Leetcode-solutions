class Solution {
public:
int n , m;
    int bfs(vector<vector<int>>& grid , vector<vector<bool>>& vis , int i , int j){
        n = grid.size(), m = grid[0].size();
        int f = 0;
        queue<pair<int, int>> q;
        q.push({i, j});
        vis[i][j] = true;

        vector<int> row = {0, 0, 1, -1};
        vector<int> col = {1, -1, 0, 0};

        while (!q.empty()) {
            i = q.front().first;
            j = q.front().second;
            q.pop();
            f += grid[i][j];

            for (int x = 0; x < 4; x++) {
                int newRow = i + row[x];
                int newCol = j + col[x];
                if (0 <= newRow && newRow < n && 0 <= newCol &&
                    newCol < m && grid[newRow][newCol] &&
                    !vis[newRow][newCol]) {
                    q.push({newRow, newCol});
                    vis[newRow][newCol] = true;
                }
            }
        }
        return f;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int cnt = 0;
        vector<vector<bool>> vis(n , vector<bool>(m , false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]>0 and !vis[i][j]){
                    cnt = max(cnt , bfs(grid,vis,i,j));
                }
            }
        }
        return cnt;
    }
};