class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;
        int currSum = 0;
        
        for(auto it:nums){
            currSum = max(currSum + it, it);
            maxSum = max(maxSum, currSum);
        }
        
        return maxSum;
    }
};