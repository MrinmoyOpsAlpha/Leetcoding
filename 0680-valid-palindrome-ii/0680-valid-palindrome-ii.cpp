class Solution {
public:
    bool isValid(string s, int l, int r, bool isCharDeleted){
        while(l<r){
            if(s[l] != s[r]){
                if(isCharDeleted) return false;
                return isValid(s,l+1,r,true) || isValid(s,l,r-1,true);
            }
            l++;
            r--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        return isValid(s,0,s.size()-1,false);
    }
};