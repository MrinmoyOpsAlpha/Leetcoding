class Solution {
private:
    int dfs(vector<vector<int>>& grid, int i ,int j){
        int n = grid.size();
        int m = grid[0].size();
        
        if(i<0 || j<0 || i>=n || j>=m) return 1;
        if(grid[i][j] == 0) return 1;
        if(grid[i][j] == -1) return 0;
        
        grid[i][j] = -1;
        int count = 0;
        count += dfs(grid,i,j+1);
        count += dfs(grid,i,j-1);
        count += dfs(grid,i+1,j);
        count += dfs(grid,i-1,j);
        
        return count;
    }
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++){
                if(grid[i][j])
                    return dfs(grid,i,j);
            }
        return 0;
    }
};