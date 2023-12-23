class Solution {
public:
    bool isPathCrossing(string path) {        
        map<char,pair<int,int>> dir;
        dir['N'] = {0,1};
        dir['E'] = {1,0};
        dir['S'] = {0,-1};
        dir['W'] = {-1,0};
        
        map<pair<int,int>,int> mp;
        mp[{0,0}] = 1;
        
        int x = 0, y = 0;
        
        for(auto it:path){
            int x_new = x + dir[it].first;
            int y_new = y + dir[it].second;
            
            if(mp.find({x_new,y_new}) != mp.end()){
                return true;
            }
            mp[{x_new,y_new}] = 1;
            
            x = x_new;
            y = y_new;
        }
        
        return false;
        
    }
};