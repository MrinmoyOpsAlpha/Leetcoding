class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long top = grid[0][0], bottom = 0, answer = LONG_MAX;
        
        for(int i=1;i<grid[0].size();i++){
            top = top + grid[0][i];
        }
        
        for(int i=0;i<grid[0].size();i++){
            top = top - grid[0][i];
            answer = min(answer,max(top,bottom));
            bottom = bottom + grid[1][i];
        }
        
        return answer;
    }
};