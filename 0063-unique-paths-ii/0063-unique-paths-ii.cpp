class Solution {    
int tabulation(vector<vector<int>>& obstacleGrid, int m, int n) {
    int dp[m][n];
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (obstacleGrid[i][j] == 1) {
                dp[i][j] = 0; // Set obstacle positions to 0
            } else {
                if (i == 0 && j == 0) {
                    dp[i][j] = 1; // Initialize the starting position to 1
                } else if (i == 0) {
                    dp[i][j] = dp[i][j - 1]; // Fill the first row
                } else if (j == 0) {
                    dp[i][j] = dp[i - 1][j]; // Fill the first column
                } else {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1]; // Fill other positions
                }
            }
        }
    }
    
    return dp[m - 1][n - 1];
}

public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        return tabulation(obstacleGrid,obstacleGrid.size(),obstacleGrid[0].size());
    }
};