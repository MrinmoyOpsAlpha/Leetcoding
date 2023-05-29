class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty()) return false;
        int n = matrix.size(), m = matrix[0].size();
        
        int row = 0, col = m - 1;
        while(row < n && col>=0){
            if(matrix[row][col] == target) return true;
            if(matrix[row][col] < target) row++;
            else col--;
        }
        
        // int low = 0, high = (m*n)-1;
        // while(low<=high){
        //     int mid = (low +high) >> 1;
        //     if(matrix[mid/m][mid%m] == target) return true;
        //     else if(matrix[mid/m][mid%m] < target) low = mid + 1;
        //     else high = mid - 1;
        // }
        
        return false;
        
        
    }
};