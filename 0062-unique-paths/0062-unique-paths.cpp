class Solution {
public:
    int dp[101][101];
    int dfsRecursive(int i,int j,int m,int n){
        if(i>=m || j>=n) return 0;
        if(i==m-1 && j==n-1 ) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j] =  dfsRecursive(i+1,j,m,n) + dfsRecursive(i,j+1,m,n);
    }
    
    int dfs(int m,int n){
        int t[m][n];
        
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++){
                if(i==0 || j==0) t[i][j]=1;                
                else {
                    t[i][j] = t[i-1][j] + t[i][j-1];
                }
            }
        return t[m-1][n-1];
    }
    int uniquePaths(int m, int n) {
        memset(dp,-1,sizeof(dp));
        return dfs(m,n);
    }
};