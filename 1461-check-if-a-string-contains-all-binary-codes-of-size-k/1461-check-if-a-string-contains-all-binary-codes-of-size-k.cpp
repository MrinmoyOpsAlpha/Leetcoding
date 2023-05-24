class Solution {
public:
    bool hasAllCodes(string s, int k) {
        set<string> all_substrings;
        int total = 1 << k ;
        
        int j = 0;
        while(j + k <= s.size()){
            all_substrings.insert(s.substr(j,k));
            j++;
        }
        
        if(all_substrings.size() == total) return true;
        else return false;
    }
};