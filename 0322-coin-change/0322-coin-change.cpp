class Solution {
    int subset(vector<int>& coins, int n,int w){
        int dp[n+1][w+1];
        for(int i=0;i<n+1;i++)
            for(int j=0;j<w+1;j++){
                 if(i==0) dp[i][j]=INT_MAX-1;
                 if(j==0) dp[i][j]=0; 
            }
        
//         for(int j=1;j<w+1;j++){
//             if(j%coins[0]==0) dp[1][j]=j/coins[0];
//             else dp[1][j]=INT_MAX-1;
//         }
        
        for(int i=1;i<n+1;i++){
            for(int j=1;j<w+1;j++){
                if(coins[i-1]>j){
                    dp[i][j]= 0 + dp[i-1][j];
                }
                
                if(coins[i-1]<=j){
                    dp[i][j]=min(1 + dp[i][j-coins[i-1]], 0 + dp[i-1][j]);
                }
            }
        }
        return dp[n][w];
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int ans = subset(coins,coins.size(),amount);     
        return ans == (INT_MAX - 1) ? -1: ans;
    }
};