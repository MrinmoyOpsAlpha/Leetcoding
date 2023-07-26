class Solution {
    int dp[1001][1001];
    int memoization(string &text1,int m, string &text2,int n){
        if(n==0 || m==0) return 0;
        if(dp[m][n] != -1) return dp[m][n];
        
        if(text1[m-1] == text2[n-1])
          return dp[m][n] =1 + memoization(text1,m-1,text2,n-1);
        else
          return dp[m][n] = max(memoization(text1,m-1,text2,n) , memoization(text1,m,text2,n-1));
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
         memset(dp,-1,sizeof(dp));
         return memoization(text1,text1.size(),text2,text2.size());
    }
};