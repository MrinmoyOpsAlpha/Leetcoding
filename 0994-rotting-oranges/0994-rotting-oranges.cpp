class Solution {
private:
    void dfs(vector<vector<int>>& grid, int i ,int j, int rot = 2){
        if(i<0 || j<0 || i>= grid.size() || j>= grid[0].size() || grid[i][j] == 0 || (1 < grid[i][j] && grid[i][j] < rot)) return;
        
        grid[i][j] = rot;
        
        dfs(grid,i+1,j,rot+1);
        dfs(grid,i-1,j,rot+1);
        dfs(grid,i,j+1,rot+1);
        dfs(grid,i,j-1,rot+1);
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == 2) 
                    dfs(grid,i,j);
            }
        }
        
        int ans = 2;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == 1) return -1;
                ans = max(ans,grid[i][j]);
            }
        }
        return ans-2;
    }
};