class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
    
        int n = nums.size();
        long long res = 0;
        int j=0;
        while (j<n/2) {
            int left = nums[j];
            int right = nums[n-1-j];
            string leftStr = to_string(left);
            string rightStr = to_string(right);
            string concat = leftStr + rightStr;
            res += stoi(concat);
            j = j+1;
        }
        if (n % 2 == 1) {
            res += nums[n/2];
        }
        return res;
    }
};