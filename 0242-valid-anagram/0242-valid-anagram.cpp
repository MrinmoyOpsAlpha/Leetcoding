class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        map<char,int> mp;
        
        for(auto &x:t){
            mp[x]++;
        }
        
        int count = mp.size();
        
        int j=0;
        
        while(j<s.size()){
            if(mp.find(s[j])!=mp.end()){
                mp[s[j]]--;
                if(mp[s[j]]==0){
                    count--;
                }
            }
            j++;
        }
        
        return count==0;
    }
};