class Solution {
public:
    int binaryGap(int n) {
        int count=INT_MIN,res=0;
        while(n){
            if(n&1) {
                res = max(res,count);
                count = 0;
            }
            count++;
            n = n >> 1;
        }
        return res;
    }
};