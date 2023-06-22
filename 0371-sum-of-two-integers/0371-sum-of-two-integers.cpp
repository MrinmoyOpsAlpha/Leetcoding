class Solution {
public:
    int getSum(int a, int b) {
        return int(log2((pow(2,a)) * (pow(2,b))));
    }
};