class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> mp;
        int i = 0, j = 0, res = 0, maxF = 0;
        
        while(j<s.size()){
            mp[s[j]]++;
            maxF = max(maxF,mp[s[j]]);
            
            if((j-i+1) - maxF > k){
                mp[s[i]]--;
                i++;
            }
            
            res = max(res,j-i+1);
            j++;
        }
        return res;
    }
};