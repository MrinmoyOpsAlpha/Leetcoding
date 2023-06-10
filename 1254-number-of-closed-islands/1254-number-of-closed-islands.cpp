class Solution {
private:
    bool dfs(vector<vector<int>>& grid,int i, int j){
        int m = grid.size();
        int n = grid[0].size();
        
        if(i<0 || i>= m || j<0 || j>=n) return false;        

        if (grid[i][j] == 1) {
            return true;
        }        
        grid[i][j] = 1;
        bool a = dfs(grid,i+1,j);
        bool b = dfs(grid,i-1,j);
        bool c = dfs(grid,i,j-1);
        bool d = dfs(grid,i,j+1);
        
        return a && b && c && d;
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        int islands = 0;
        
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++){
                if(grid[i][j] == 0){
                    if(dfs(grid,i,j)){
                        islands++;
                    }
                }
            }
        return islands;
    }
};