class Solution {
private:
    void dfs(vector<vector<char>>& grid,int i,int j){
        int m = grid.size();
        int n = grid[0].size();
        
        if(i>= m || j>=n || i<0 || j<0 || grid[i][j] == '0' || grid[i][j] == '2') return ;
        
        grid[i][j] = '2';
        dfs(grid,i-1,j);
        dfs(grid,i+1,j);
        dfs(grid,i,j-1);
        dfs(grid,i,j+1);
    }    
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        int cnt = 0;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == '1'){
                    dfs(grid,i,j);
                    cnt++;
                }
            }
        }
        
        return cnt;
    }
};