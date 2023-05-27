class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0, j = 0, minLen = INT_MAX, sum = 0;
        while(j< nums.size()){
            sum += nums[j];
            while(sum >= target){
                minLen = min(minLen, j-i+1);
                sum -= nums[i];
                i++;
            }
            j++;
        }
        return minLen == INT_MAX ? 0 : minLen;
    }
};