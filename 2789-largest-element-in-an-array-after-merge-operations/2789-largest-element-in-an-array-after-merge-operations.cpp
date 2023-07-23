class Solution {
public:
    long long maxArrayValue(vector<int>& nums) {
        int n = nums.size();
        long long ans = nums[n-1], sum = nums[n-1];
        
        for (long long i = n-2; i >=0; i--) {
            if(nums[i] <= sum) sum += nums[i];
            else sum = nums[i];
            
            ans = max(ans,sum);
        }
        
        return ans;
    }
};
