class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        int n = nums.size();
        int prev = nums[n-1];
        long long int ans = 0;
        
        for(int i = n-2;i>=0;i--){
            if(nums[i] > prev){
                long long int total_divide = (nums[i] - 1) / prev;
                prev = nums[i] / (total_divide + 1);
                ans = ans + total_divide;
            }
            else{
                prev = nums[i];
            }
        }
        
        return ans;
    }
};