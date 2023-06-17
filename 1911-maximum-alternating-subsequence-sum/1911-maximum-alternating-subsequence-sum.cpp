class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long maxProfit=nums[0];
        
        for(int i=1; i<nums.size(); ++i) 
            maxProfit += max(nums[i] - nums[i-1], 0);
   
        return maxProfit;
    }
};