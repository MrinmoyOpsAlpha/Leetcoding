class Solution {
    int dfs(vector<vector<int>>& grid,int i, int j,int steps,int totalsteps){
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == -1) return 0;
        
        if(grid[i][j] == 2){
            return (steps == totalsteps) ? 1 : 0;
        }
        
        grid[i][j] = -1;
        
        int paths = dfs(grid,i,j-1,steps+1,totalsteps)
                    + dfs(grid,i,j+1,steps+1,totalsteps)
                    + dfs(grid,i-1,j,steps+1,totalsteps)
                    + dfs(grid,i+1,j,steps+1,totalsteps);
        
        grid[i][j] = 0;
        
        return paths;
    }
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int totalsteps = 0;
        
        int start_i = 0 , start_j = 0;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    start_i = i;
                    start_j = j; 
                }
                else if(grid[i][j] != -1){
                    totalsteps++;
                }
            }
        }
        
        return dfs(grid,start_i,start_j,0,totalsteps);
    }
};