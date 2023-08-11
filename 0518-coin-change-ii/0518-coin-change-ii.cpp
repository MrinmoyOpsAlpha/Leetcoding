class Solution {
    int subsetHelper(vector<int>& coins, int n, int w, int** dp) {
        if (w == 0) {
            return 1; 
        }
        if (n == 0) {
            return 0; 
        }

        if (dp[n][w] != -1) {
            return dp[n][w];
        }

        int waysWithoutCurrentCoin = subsetHelper(coins, n - 1, w, dp); 
        int waysWithCurrentCoin = 0;
        if (coins[n - 1] <= w) {
            waysWithCurrentCoin = subsetHelper(coins, n, w - coins[n - 1], dp); 
        }
        
        dp[n][w] = waysWithoutCurrentCoin + waysWithCurrentCoin;
        return dp[n][w];
    }
    int subset(vector<int>& coins, int n, int w){
        int dp[n+1][w+1];
        for(int i=0;i<n+1;i++)
            for(int j=0;j<w+1;j++){
                if(i == 0) dp[i][j] = 0;
                if(j == 0) dp[i][j] = 1;
            }
        
        for(int i=1;i<n+1;i++)
            for(int j=1;j<w+1;j++){
                if(coins[i - 1] > j){
                    dp[i][j] = dp[i-1][j];
                }
                else{
                    dp[i][j] =  dp[i-1][j] + dp[i][j - coins[i - 1]];
                }
            }
        return dp[n][w];
        
    }
public:
    int change(int amount, vector<int>& coins) {
        return subset(coins,coins.size(),amount);
    }
};