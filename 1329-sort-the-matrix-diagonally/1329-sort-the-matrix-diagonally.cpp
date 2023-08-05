class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        
        map<int,priority_queue<int,vector<int>, greater<int>>> mp;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                mp[j-i].push(mat[i][j]);
            }
        }
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                mat[i][j] = mp[j-i].top();
                mp[j-i].pop();
            }
        }
        
        return mat;
    }
};