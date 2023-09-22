class Solution {
private:
    int dp[101][10001];
    int lcs(string s,string t,int x,int y){
        if(x==0 || y==0) return 0;
        
        if(dp[x][y] != -1) return dp[x][y];
        
        int take = 0 , nottake = 0;
        
        if(s[x-1] == t[y-1]){
            take = 1 + lcs(s,t,x-1,y-1);
        }
        
        else{
            nottake = 0 + max(lcs(s,t,x-1,y), lcs(s,t,x,y-1));
        }
        
        return dp[x][y] = max(take,nottake);
    }
public:
    bool isSubsequence(string s, string t) {
         memset(dp,-1,sizeof(dp));
        return lcs(s,t,s.size(),t.size()) == s.size();
    }
};