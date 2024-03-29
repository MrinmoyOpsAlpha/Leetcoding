class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>> mp;
        
        for(auto s:strs){
            string t = s;
            sort(t.begin(),t.end());
            mp[t].push_back(s);
        }
        
        vector<vector<string>> ans;
        for(auto x:mp){
            ans.push_back(x.second);
        }
        return ans;
    }
};