class Solution {
    int dp[101][101];
    int dfs(vector<vector<int>>& obstacleGrid, int i, int j) {
        if (i >= obstacleGrid.size() || j >= obstacleGrid[0].size() || obstacleGrid[i][j] == 1) {
            return 0;
        }
        
        if (i == obstacleGrid.size() - 1 && j == obstacleGrid[0].size() - 1) {
            return 1;
        }
        
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        
        return dp[i][j] = dfs(obstacleGrid, i + 1, j) + dfs(obstacleGrid, i, j + 1);
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        memset(dp, -1, sizeof(dp));
        return dfs(obstacleGrid, 0, 0);
    }
};
