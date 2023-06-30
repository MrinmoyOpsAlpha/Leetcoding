class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int ans = 0;
        int m = mat.size();
        
        for(int i=0;i<m;i++){
            ans = ans + mat[i][i];
            ans = ans + mat[m-i-1][i];
        }
        return m % 2 == 0 ? ans : ans - mat[m/2][m/2];
    }
};