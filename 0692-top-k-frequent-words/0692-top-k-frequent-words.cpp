class Solution {
    static bool comparator(pair<string,int> a,pair<string,int> b){
        if(a.second > b.second || (a.second == b.second && a.first < b.first)){
            return true;
        }
        return false;
    }
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> mp;
        
        for(auto w:words){
            mp[w]++;
        }
        
        vector<pair<string,int>> v;
        for(auto it:mp){
            v.push_back({it.first,it.second});
        }
        
        sort(v.begin(),v.end(),comparator);
        
        vector<string> ans;
        for(int i=0;i<k;i++){
            ans.push_back(v[i].first);
        }
        return ans;
    }
};