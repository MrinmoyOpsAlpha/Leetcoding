class Solution {
    int MOD = 1e9 + 7;
    
    int helper(int n , int k , int target, int sum, int ways,vector<vector<int>> &dp){
        if(n == ways){
            return (target == sum) ?  1 : 0;
        }
        
        if(dp[sum][ways] != -1) return dp[sum][ways];
        
        long long ans = 0;
        for(int i=1;i<=k;i++){
            if(sum + i <= target)
                ans = ans + helper(n , k , target, sum + i, ways + 1,dp);
        }
        
        return dp[sum][ways] = ans % MOD;
    }
public:
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(target + 1, vector<int>(n+1, -1));
        return helper(n,k,target,0,0,dp);
    }
};