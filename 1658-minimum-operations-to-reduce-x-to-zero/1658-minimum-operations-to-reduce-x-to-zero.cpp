class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int targetSum = accumulate(nums.begin(),nums.end(),0);
        targetSum -= x;
        
        if(targetSum == 0) return n;
        int maxLength = 0, left = 0, right = 0,  currSum = 0;
        
        while(right < n){
            currSum += nums[right];
            
            while(left <= right && currSum > targetSum){
                currSum -= nums[left];
                left++;
            }
            
            if(currSum == targetSum){
                maxLength = max(maxLength , right-left+1);
            }
            
            right++;
        }
        
        return maxLength != 0 ? n - maxLength : -1;
    }
};