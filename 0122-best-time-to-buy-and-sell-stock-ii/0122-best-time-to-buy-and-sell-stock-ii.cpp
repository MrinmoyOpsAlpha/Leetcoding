class Solution {
    int solve(vector<int>& prices,int index,bool canBuy, vector<vector<int>> &dp){
        if(index >= prices.size()) return 0;
        if(dp[index][canBuy] != -1) return dp[index][canBuy];
        
        int take = 0, nottake = 0;
        
        if(canBuy){
            take = -prices[index] + solve(prices,index+1,false,dp);
            nottake = solve(prices,index+1,true,dp);
        }
        
        else{
            take = prices[index] + solve(prices,index+1,true,dp);
            nottake = solve(prices,index+1,false,dp);
        }
        
        return dp[index][canBuy] = max(take,nottake);
    }
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        return solve(prices,0,true,dp);
    }
};