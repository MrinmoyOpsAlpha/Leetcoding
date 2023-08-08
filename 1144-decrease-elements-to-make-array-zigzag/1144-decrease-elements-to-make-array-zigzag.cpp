class Solution {
    int solve(vector<int>& nums,int startIndex){
        int ans = 0;
        
        for(int i= startIndex;i<nums.size();i+=2){
            int left = (i != 0) ? nums[i-1] : INT_MAX;
            int right = (i < nums.size() - 1) ? nums[i+1] : INT_MAX;
            ans += max(0, nums[i] - min(left,right) + 1);
        }
        return ans;
    }
    
public:
    int movesToMakeZigzag(vector<int>& nums) {
        return min(solve(nums,0),solve(nums,1));
    }
};