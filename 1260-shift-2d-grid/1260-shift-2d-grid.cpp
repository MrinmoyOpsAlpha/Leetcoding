class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        
        // Calculate the total number of elements in the grid
        int totalElements = m * n;
        
        // Calculate the effective number of shifts
        k %= totalElements;
        
        vector<vector<int>> newGrid(m, vector<int>(n, 0));
        
        // Calculate the new indices for each element
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int newRow = (i + (j + k) / n) % m;
                int newCol = (j + k) % n;
                newGrid[newRow][newCol] = grid[i][j];
            }
        }
        
        return newGrid;
    }
};
