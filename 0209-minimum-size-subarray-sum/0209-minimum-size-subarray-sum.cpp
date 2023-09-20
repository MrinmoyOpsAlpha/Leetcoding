class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minLength = INT_MAX, n = nums.size(), left = 0, right = 0, currSum = 0;
        
        while (right < n) {
            currSum += nums[right];
            
            while (left <= right && currSum >= target) {
                minLength = min(minLength, right - left + 1);
                currSum -= nums[left];
                left++;
            }
            
            right++;
        }
        
        return minLength != INT_MAX ? minLength : 0;
    }
};
