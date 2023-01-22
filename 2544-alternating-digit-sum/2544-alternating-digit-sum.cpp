class Solution {
public:
    int alternateDigitSum(int n) {
        int res = 0,count = 0;
        string s = to_string(n);
        
        for(auto ch:s){
            if(count%2==0) res = res + (ch - '0');
            else res = res - (ch - '0');
            count++;
        }
        return res;
    }
};