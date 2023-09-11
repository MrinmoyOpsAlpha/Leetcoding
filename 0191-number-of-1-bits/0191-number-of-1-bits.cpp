class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt = 0;
        
        while(n){
            cnt += n % 2;
            n = n >> 1;
        }
        
        return cnt;
    }
};