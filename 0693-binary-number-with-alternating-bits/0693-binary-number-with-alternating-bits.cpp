class Solution {
    bool helper(int n,int prev){
        if (n==0) return true;
        
        else if (((n&1) && prev) || (!(n&1) && !prev)) return false;
        
         return helper(n>>1,n&1);
    }
public:
    bool hasAlternatingBits(int n) {
        return helper(n>>1,n&1);
    }
};