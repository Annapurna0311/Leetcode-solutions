class Solution {
public:
const int MOD = 1e9 + 7;
    int countPathsWithXorValue(vector<vector<int>>& grid, int k) {
        int m = grid.size() , n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(16, 0)));
        dp[0][0][grid[0][0]] = 1;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int xor_val = 0; xor_val < 16; ++xor_val) {
                    if (dp[i][j][xor_val] > 0) {
                        if (i + 1 < m) {
                            int new_xor = xor_val ^ grid[i + 1][j];
                            dp[i + 1][j][new_xor] = (dp[i + 1][j][new_xor] + dp[i][j][xor_val]) % MOD;
                        }
                        if (j + 1 < n) {
                            int new_xor = xor_val ^ grid[i][j + 1];
                            dp[i][j + 1][new_xor] = (dp[i][j + 1][new_xor] + dp[i][j][xor_val]) % MOD;
                        }
                    }
                }
            }
        }
        return dp[m - 1][n - 1][k];
    }
};