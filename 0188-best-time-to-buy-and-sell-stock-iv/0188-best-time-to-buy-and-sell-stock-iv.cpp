class Solution {
    int solve(vector<int>& prices,int index,int buy,int times,vector<vector<vector<int>>> &dp){
        if(index >= prices.size() || times == 0) return 0;        
        if(dp[index][buy][times] != -1) return dp[index][buy][times];
        
        int take = 0, nottake = 0;
        
        if(buy){
            take = -prices[index] + solve(prices,index+1,false,times,dp);
            nottake = solve(prices,index+1,true,times,dp);
        }
        
        else{
            take = prices[index] + solve(prices,index+1,true,times-1,dp);
            nottake = solve(prices,index+1,false,times,dp);
        }
        
        
        return dp[index][buy][times] = max(take,nottake);
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(2, vector<int>(k + 1, -1)));

        return solve(prices,0,true,k,dp);
    }
};