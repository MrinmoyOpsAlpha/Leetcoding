class Solution {
    long long helper(string text, string pattern){
        long long ans = 0;
        unordered_map<char,long long> mp;
        for(auto x:text){
            if(x == pattern[1]){
                ans = ans + mp[pattern[0]];
            }
            mp[x]++;
        }
        return ans;
    }
public:
    long long maximumSubsequenceCount(string text, string pattern) {
        return max(helper(pattern[0] + text, pattern),helper(text + pattern[1], pattern));
    }
};