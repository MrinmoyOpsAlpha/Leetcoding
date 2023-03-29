class Solution {
public:
    int characterReplacement(string s, int k) {
        
        unordered_map<char,int> mp;
        
        int i=0,j=0, res = -1, maxRepeatingElements = 0;
        
        while(j<s.size()){
            
            mp[s[j]]++;
            maxRepeatingElements = max(maxRepeatingElements , mp[s[j]]);
            
            int windowLength = j - i + 1;
            
            if(windowLength - maxRepeatingElements > k){
                mp[s[i]]--;
                i++;
            }
            
            windowLength = j-i+1;
            res = max(res,windowLength);
            j++;
        }
        return res;
    }
};