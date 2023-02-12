class Solution {
public:
    long long countLess(vector<int>& nums, int val) {
        long long res = 0;
        int i = 0, j = nums.size() - 1;
        while (i < j) {
            while(i < j && nums[i] + nums[j] >= val)
                --j;
            res += j - i;
            i++;
        } 
      
        return res;
    }
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(begin(nums), end(nums));
        return countLess(nums, upper+1) - countLess(nums, lower);
    }
};