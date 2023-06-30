class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n,0));
        if(n == 0) return res;
        int left = 0, right = n-1, top = 0, bottom = n-1;
        int dir = 0;
        int x = 1;
        
        while(left<=right && top<=bottom){
            if(dir == 0){
                for(int i=left;i<=right;i++){
                    res[top][i] = x++;
                }
                top++;
            }
            else if(dir == 1){
                for(int i=top;i<=bottom;i++){
                    res[i][right] = x++;
                }
                right--;
            }
            
            else if(dir == 2){
                for(int i=right;i>=left;i--){
                    res[bottom][i] = x++;
                }
                bottom--;
            }
            
            else if(dir == 3){
                for(int i=bottom;i>=top;i--){
                    res[i][left] = x++;
                }
                left++;
            }
            dir = (1 + dir) % 4;
        }
        return res;
    }
};