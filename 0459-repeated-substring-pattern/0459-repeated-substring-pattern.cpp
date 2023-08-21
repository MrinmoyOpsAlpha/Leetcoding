class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int i = 0, j = 0 ;
        string res = "";
        
        while(j < s.size() / 2){
            res += s[j];
            string temp = res;
            while(temp.size() < s.size()){
                temp += res;
            }
            
            if(temp == s) return true;
            j++;
        }
        
        return false;
    }
};