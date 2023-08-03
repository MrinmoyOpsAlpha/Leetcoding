class Solution {
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        int dist = abs(target[1]) + abs(target[0]);
        bool flag = true;
        for(int i=0;i<ghosts.size();i++){
            int x_new = ghosts[i][0];
            int y_new = ghosts[i][1];
            
            if(abs(target[0] - x_new) + abs(target[1]-y_new) <= dist){
                flag = false;
            }
        }
        
        return flag;
    }
};