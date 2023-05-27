class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> mp;
        int count  = 0 , i = 0, j= 0;
        
        while(j<s.size()){
            mp[s[j]]++;
            while(mp[s[j]] > 1){
                mp[s[i]]--;
                i++;
            }
            
            count = max(count,j-i+1);
            j++;
        }
        return count;
    }
};