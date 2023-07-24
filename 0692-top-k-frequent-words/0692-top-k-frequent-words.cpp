class Solution {
    static bool comparator(pair<string,int> a,pair<string,int> b){
        if(a.second > b.second || (a.second == b.second && a.first < b.first)){
            return true;
        }
        return false;
    }
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> freq;
        for(auto w:words){
            freq[w]++;
        }
        
        vector<pair<string,int>> v;
        for(auto it:freq){
            v.push_back({it.first,it.second});
        }
        
        sort(v.begin(),v.end(),comparator);
        
        vector<string> res;
        for(int i=0;i<k;i++){
            res.push_back(v[i].first);
        }
        return res;
    }
};