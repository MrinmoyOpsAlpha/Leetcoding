class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int total = 0;
        int currMax = 0, maxSum = INT_MIN;
        int currMin = 0, minSum = INT_MAX;
        
        for(auto it:nums){
            currMax = max(currMax + it,it);
            maxSum = max(maxSum, currMax);
            
            currMin = min(currMin + it,it);
            minSum = min(minSum, currMin);
            
            total += it;
        }
        
        return maxSum > 0 ? max(maxSum, total - minSum) : maxSum;
    }
};
