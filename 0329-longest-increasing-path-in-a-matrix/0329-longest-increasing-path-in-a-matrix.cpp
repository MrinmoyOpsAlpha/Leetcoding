class Solution {
    int dfs(vector<vector<int>>& matrix ,int i, int j, int prev,vector<vector<int>>& dp){
        if (i < 0 || j < 0 || i == matrix.size() || j == matrix[0].size() || prev >= matrix[i][j]) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        int left = dfs(matrix,i,j-1,matrix[i][j],dp);
        int right = dfs(matrix,i,j+1,matrix[i][j],dp);
        int down = dfs(matrix,i+1,j,matrix[i][j],dp);
        int up = dfs(matrix,i-1,j,matrix[i][j],dp);
        
        return dp[i][j] = max({left,right,up,down}) + 1;
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int cnt = 0;
        vector<vector<int>> dp(matrix.size(), vector<int> (matrix[0].size(), -1)); 
        for(int i=0;i<matrix.size();i++)
            for(int j=0;j<matrix[0].size();j++){
                cnt = max(cnt,dfs(matrix,i,j,-1,dp));
            }
        
        return cnt;
    }
};