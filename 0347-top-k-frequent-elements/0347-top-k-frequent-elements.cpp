class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> mp;
        for(auto x:nums){
            mp[x]++;
        }
        
        priority_queue<pair<int,int>> pq;
        vector<int> ans;
        
        for(auto it:mp){
            pq.push({it.second,it.first});
            
            if(pq.size() > mp.size() - k){
                ans.push_back(pq.top().second);
                pq.pop();
            }
        }
        return ans;
    }
};