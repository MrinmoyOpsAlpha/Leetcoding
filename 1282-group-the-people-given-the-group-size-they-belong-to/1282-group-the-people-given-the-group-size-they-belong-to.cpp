class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n = groupSizes.size();
        vector<vector<int>> res;
        
        map<int,vector<int>> mp;
        
        for(int i=0;i<n;i++){
            int key = groupSizes[i];
            
            if(mp.count(key) > 0){
                mp[key].push_back(i);
            }
            
            else{
                mp[key] = vector<int>{i};
            }
            
            if(mp[key].size() == key){
                res.push_back(mp[key]);
                mp.erase(key);
            }
        }
        
        return res;        
    }
};