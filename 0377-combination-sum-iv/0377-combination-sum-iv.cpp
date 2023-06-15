class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        unordered_map<int, int> memo;
        return combinationSum4Recursive(nums, target, memo);
    }
    
private:
    int combinationSum4Recursive(vector<int>& nums, int target, unordered_map<int, int>& memo) {
        if (target == 0) {
            return 1;
        }
        
        if (memo.count(target)) {
            return memo[target];
        }
        
        int count = 0;
        for (int x : nums) {
            if (target >= x) {
                count += combinationSum4Recursive(nums, target - x, memo);
            }
        }
        
        memo[target] = count;
        return count;
    }
};
