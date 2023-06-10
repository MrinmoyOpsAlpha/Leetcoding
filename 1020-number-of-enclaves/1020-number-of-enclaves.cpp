class Solution {
    int dfs(vector<vector<int>>& grid,int i,int j){
        int m = grid.size();
        int n = grid[0].size();
        
        if(i<0 || i>=m || j<0 || j>=n || grid[i][j] == 0) return 0;
        
        grid[i][j] = 0;
        
        return 1+dfs(grid,i+1,j)+dfs(grid,i-1,j)+dfs(grid,i,j+1)+dfs(grid,i,j-1);
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        int total = 0;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    total += 1;
                }
            }
        
        int ans = 0;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++){
                if((i==0 || j==0 || i==m-1 || j==n-1) && grid[i][j]==1){
                    ans += dfs(grid,i,j);
                }
            }
        return total - ans ;
    }
};