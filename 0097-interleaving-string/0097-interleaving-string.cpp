class Solution {
    int dp[101][101];
    bool solve(string s1, string s2, string s3,int a,int b,int c){
        if(c == 0) return true;
        
       if(dp[a][b]!=-1)
            return dp[a][b];
        
        bool choice1 = false, choice2 = false;
        
        if(a-1 >=0 && s3[c-1] == s1[a-1]){
            choice1 = solve(s1,s2,s3,a-1,b,c-1);
        }
        
        if(b-1 >=0 && s3[c-1] == s2[b-1]){
            choice2 = solve(s1,s2,s3,a,b-1,c-1);
        }
        
        return dp[a][b] = choice1 + choice2;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        int a = s1.size();
        int b = s2.size();
        int c = s3.size();
        
        memset(dp,-1,sizeof(dp));
        
        if(a+b != c) return 0;
        
        return solve(s1,s2,s3,a,b,c);
    }
};