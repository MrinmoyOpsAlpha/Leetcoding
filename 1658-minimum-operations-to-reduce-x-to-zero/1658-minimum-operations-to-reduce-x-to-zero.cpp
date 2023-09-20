class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int target = 0, n = nums.size();
        
        for(auto it:nums) target += it;
        
        target = target - x;
        if (target == 0) return n;
        
        int maxLen = 0, currSum = 0,left = 0, right = 0;
        
        while(right < n){
            currSum = currSum + nums[right];
            
            while(left <= right && currSum > target){
                currSum = currSum - nums[left];
                left++;
            }
            
            if(currSum == target) {
                maxLen = max(maxLen, right-left+1);
            }
            right++;
        }
        
        return maxLen != 0 ? n - maxLen : -1;
    }
};