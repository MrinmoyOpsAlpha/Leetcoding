class Solution {
    int solve(vector<int>& prices,int index,bool canBuy,int cap, vector<vector<vector<int>>> &dp){
        if(index >= prices.size() || cap == 0 ) return 0;
        if(dp[index][canBuy][cap] != -1) return dp[index][canBuy][cap];
        
        int take = 0, nottake = 0;
        
        if(canBuy){
            take = -prices[index] + solve(prices,index+1,false,cap,dp);
            nottake = solve(prices,index+1,true,cap,dp);
        }
        
        else{
            take = prices[index] + solve(prices,index+1,true,cap-1,dp);
            nottake = solve(prices,index+1,false,cap,dp);
        }
        
        return dp[index][canBuy][cap] = max(take,nottake);
    }
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size(),vector<vector<int>>(2,vector<int>(3,-1)));
        return solve(prices,0,true,2,dp);
    }
};