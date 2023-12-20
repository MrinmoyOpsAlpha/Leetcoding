class Solution {
private:
    void turnbox(vector<vector<char>>& box,vector<vector<char>>& matrix){
        int m = box.size(), n = box[0].size();
        
        for(int i=0, c = m-1 ;i<m;i++,c--){
            for(int j=0, r=0;j<n;j++, r++){
                matrix[r][c] = box[i][j];
            }
        }
    }
    
    
    void gravity(vector<vector<char>>& matrix){
        int m = matrix.size(), n = matrix[0].size();
        
        for(int c = 0; c < n; c++){
            int last  = m-1;
            for(int r = m-1; r >= 0; r--){
                char val =  matrix[r][c];
                if(val == '.') continue;
                if(val == '*') last = r-1;
                if(val == '#') {
                    matrix[r][c] = '.';
                    matrix[last][c] = '#';
                    last--;
                }
            }
        }
    }
    
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size(), n = box[0].size();
        vector<vector<char>> matrix(n,vector<char>(m));
        
        turnbox(box,matrix);
        
        gravity(matrix);
        
        return matrix;
    }
};