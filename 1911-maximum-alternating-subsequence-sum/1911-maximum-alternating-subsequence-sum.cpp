class Solution {
    long long solve(vector<int>& nums,int index,bool alternate,vector<vector<long long>> &dp){
        if(index>=nums.size()) return 0;
        if(dp[index][alternate] != -1) return dp[index][alternate];
        
        long long take = 0, nottake = 0;
        if(alternate){
            take = nums[index] + solve(nums,index+1,false,dp);
            nottake = solve(nums,index+1,true,dp);
        }
        
        else{
            take = -nums[index] + solve(nums,index+1,true,dp);
            nottake = solve(nums,index+1,false,dp);
        }
        
        return dp[index][alternate] = max(take,nottake);
    }
public:
    long long maxAlternatingSum(vector<int>& nums) {
        vector<vector<long long>> dp(nums.size(),vector<long long>(2,-1));
        return solve(nums,0,true,dp);
    }
};