class Solution {
public:
    int minOperations(int n) {
        int nearPower = log2(n);
        int a = pow(2,nearPower);
        int b = pow(2,nearPower + 1);
        
        if(n-a==0 || b-n==0 ) return 1;
        return min (minOperations(n-a) + 1 , minOperations(b-n) + 1);
    }
};