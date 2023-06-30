class Solution {
    int dfs(int n,vector<int> &dp){
        if(n<=0) return 0;
        if(dp[n] != -1) return dp[n];
        for(int i=1;i * i<=n;i++){
            if(dfs(n - (i*i),dp) == 0)
                return dp[n] = 1;
        }
        
        return dp[n] = 0;
    }
public:
    bool winnerSquareGame(int n) {
        vector<int> dp(n+1, -1);
        return dfs(n,dp);
    }
};