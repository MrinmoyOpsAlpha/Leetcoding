class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int totalElements = m * n;
        k %= totalElements;
        
        while(k--){
            int previous = grid[m - 1][n - 1];
            
            for(int i=0;i<m;i++)
                for(int j=0;j<n;j++){
                    int temp = grid[i][j];
                    grid[i][j] = previous;
                    previous = temp;
                }
        }
        return grid;
    }
};