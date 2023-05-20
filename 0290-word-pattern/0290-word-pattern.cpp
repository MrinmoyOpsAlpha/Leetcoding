class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> v;
        string word;
        stringstream ss(s);
        
        while(ss >> word){
            v.push_back(word);
        }
        
        if(pattern.size()!=v.size()) return false;
        
        unordered_map<char,string> mp;
        set<string> st;
        
        for(int i=0;i<pattern.size();i++){
            if(mp.find(pattern[i]) != mp.end()){
                if(mp[pattern[i]] != v[i]){
                    return false;
                }
            }
            else{
                if(st.count(v[i]) > 0){
                    return false;
                }
                
                mp[pattern[i]] = v[i];
                st.insert(v[i]);
            }
        }
        return true;
    }
};