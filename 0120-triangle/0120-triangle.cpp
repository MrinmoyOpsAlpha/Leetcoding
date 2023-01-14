class Solution {
public:
    //memoization
    int helper(int i,int j ,int n,vector<vector<int>>& triangle,vector<vector<int>> &dp ){
        if(i==n) return 0;
        if(dp[i][j] !=-1) return dp[i][j] ; 
        int left = triangle[i][j] + helper(i+1,j,n,triangle,dp);
        int right = triangle[i][j] + helper(i+1,j+1,n,triangle,dp);
        return dp[i][j] = min(left,right);
    }
    
    //tabulation
    int tabulation(vector<vector<int>>& triangle,int n){        
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int j=0;j<n;j++) dp[n-1][j] = triangle[n-1][j];
        for(int i=n-2;i>=0;i--)
            for(int j=i;j>=0;j--)
            {
                int left = triangle[i][j] + dp[i+1][j];
                int right = triangle[i][j] + dp[i+1][j+1];
                dp[i][j] = min(left,right);
            }
        return dp[0][0];
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        return tabulation(triangle,n);
    }
};