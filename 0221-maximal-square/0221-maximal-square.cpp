class Solution {
    int dfs(vector<vector<char>>& matrix,int i,int j,vector<vector<int>> &dp){
        if(i<0 || j<0 || i>= matrix.size() || j>= matrix[0].size() || matrix[i][j] == '0' ) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int right = dfs(matrix,i,j+1,dp);
        int down = dfs(matrix,i+1,j,dp);
        int rightdown = dfs(matrix,i+1,j+1,dp);
        
        return dp[i][j] = 1 + min({right,down,rightdown});
    }
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        
        int ans = 0;
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), -1));
        for(int i=0;i<matrix.size();i++)
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j] == '1')
                    ans = max(ans,dfs(matrix,i,j,dp));
            }
        
        return ans*ans;
    }
};