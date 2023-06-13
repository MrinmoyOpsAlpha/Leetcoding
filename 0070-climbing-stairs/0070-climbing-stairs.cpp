class Solution {
public:
    int climbStairs(int n) {
        if(n<1) return 0;
        vector<int> dp(n+1);
        dp[0] = dp[1] = 1;
        for(int i=2;i<=n;i++){
            dp[i] = dp[i-2] + dp[i-1];
        }
        return dp[n];
    }
};