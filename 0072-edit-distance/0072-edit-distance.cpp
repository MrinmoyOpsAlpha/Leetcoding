class Solution {
public:
    //using recursion
    int editRecursion(string s,string t,int i,int j){
        if(i==0) return j;
        if(j==0) return i;
        
        if(s[i-1]==t[j-1]){
            return editRecursion(s,t,i-1,j-1);
        }
        else{
            int insertChar = editRecursion(s,t,i,j-1);
            int deleteChar = editRecursion(s,t,i-1,j);
            int replaceChar = editRecursion(s,t,i-1,j-1);
            return 1 + min({insertChar,deleteChar,replaceChar});
        }
    }
    
    //using bottom-up dp
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