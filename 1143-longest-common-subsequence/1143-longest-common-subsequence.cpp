class Solution {
public:
    
    int dp[1001][1001];
    
    int maxLen(string& s1, string& s2, int n, int m)
    {
        if(n==0 || m==0 )return 0;
        
        if(dp[n][m]!=-1) return dp[n][m];
        
        if(s1[n-1]==s2[m-1]) return dp[n][m] = 1 + maxLen(s1,s2,n-1,m-1);
        
        else{
            return dp[n][m] = max(maxLen(s1,s2,n-1,m),maxLen(s1,s2,n,m-1));
        }
    }
    
    int lcs(string& s1,string& s2,int m,int n){
        int t[m+1][n+1];
        
        for(int i=0;i<m+1;i++)
            for(int j=0;j<n+1;j++)
                if(i==0 || j==0) t[i][j]=0;
        
        for(int i=1;i<m+1;i++)
            for(int j=1;j<n+1;j++){
                if(s1[i-1]==s2[j-1]) t[i][j] = 1 + t[i-1][j-1];
                
                else{
                    t[i][j]= max (t[i-1][j],t[i][j-1]);
                }
            }
                
        return t[m][n];
    }
    
    
    int longestCommonSubsequence(string text1, string text2) {
        
        // memset(dp,-1,sizeof(dp));
        // return maxLen(text1,text2,text1.size(),text2.size());
        return lcs(text1,text2,text1.size(),text2.size());
    }
};