class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0, j = 0, res = INT_MAX, sum = 0;
        while(j < nums.size()){
            sum = sum + nums[j];
            while(sum >= target){
                sum = sum - nums[i];
                res = min(res, j-i+1);
                i++;
            }
            j++;
        }
        
        return res == INT_MAX ? 0 : res;
    }
};