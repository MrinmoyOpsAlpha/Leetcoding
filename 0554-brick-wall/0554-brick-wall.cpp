class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int,int> countGap;
        
        for(int i=0;i<wall.size();i++){
            int pos = 0;
            for(int j=0;j<wall[i].size()-1;j++){
                pos = pos + wall[i][j];
                countGap[pos]++;
            }
        }
        
        int crossedBricks = 0;
        for(auto it: countGap){
            crossedBricks = max(crossedBricks,it.second);
        }
        
        return wall.size() - crossedBricks;
    }
};