class Solution {
    int mod = 1e9+7;
    int dp[301][301];
    
    int helper(int n,int num,int x){
        if(n < 0) return 0;
        if(n==0) return 1;
        
        if(pow(num,x) > n) return 0;
        
        if(dp[n][num] != -1) return dp[n][num];        
        int temp = pow(num,x);
        
        int take = helper(n - temp, num+1, x);
        int not_take = helper(n,num+1,x);
        
        return dp[n][num] = (take % mod + not_take % mod) % mod;
    }
public:
    int numberOfWays(int n, int x) {
        memset(dp, -1, sizeof(dp));
        return helper(n, 1, x);
    }
};