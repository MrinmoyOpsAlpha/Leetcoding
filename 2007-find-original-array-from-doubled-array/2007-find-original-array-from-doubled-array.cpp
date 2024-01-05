class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        if(changed.size() & 1){
            return {};
        }
        
        sort(changed.begin(), changed.end());
        
        map<int,int> mp;
        for(auto it:changed){
            mp[it]++;
        }
        
        vector<int> res;
        for(auto it:changed){
            if(mp[it] == 0) continue;
            if(mp[it*2] == 0 ) return {};
            res.push_back(it);
            mp[it]--;
            mp[it*2]--;
        }
        return res;
    }
};