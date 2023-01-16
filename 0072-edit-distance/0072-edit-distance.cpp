class Solution {
public:
    int edit_distance(string s,string t,int m,int n){
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
         for (int i = 1; i <= m; i++) {
                dp[i][0] = i;
            }
        
         for (int j = 1; j <= n; j++) {
            dp[0][j] = j;
            }
        
 
        for(int i=1;i<m+1;i++)
            for(int j=1;j<n+1;j++){
                if(s[i-1]==t[j-1]) dp[i][j] = dp[i-1][j-1];
                else{
                   dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])) + 1;
                }
            }
        
        return dp[m][n];
    }
    
    int minDistance(string word1, string word2) {
        return edit_distance(word1,word2,word1.size(),word2.size());
    }
};