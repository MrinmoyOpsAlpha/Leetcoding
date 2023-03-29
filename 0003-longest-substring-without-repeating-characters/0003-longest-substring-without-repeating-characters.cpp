class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> mp;
        int i=0,j=0,res=0;
        
        while(j<s.size()){
            mp[s[j]]++;
            
            while(mp[s[j]]>1){
                mp[s[i]]--;
                i++;
            }
            
            res = max(res,j-i+1);
            j++;
            
        }
        
        return res;
    }
};