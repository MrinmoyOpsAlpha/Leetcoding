class Solution {
    long long memo[100005][2];
    long long helper(int index,int prev,vector<int>& nums, int x){
        if(index >= nums.size()) return 0;
        if(memo[index][prev] != -1)return memo[index][prev];
        
        long long take = nums[index] + helper(index + 1,(nums[index]&1),nums,x);
        long long not_take = 0 + helper(index+1,prev, nums,x);
        
        if((nums[index]&1) != prev) take -= x;
        return memo[index][prev] = max(take,not_take);
    }
public:
    long long maxScore(vector<int>& nums, int x) {
        memset(memo, -1, sizeof(memo));
        return nums[0] + helper(1,(nums[0]&1),nums,x);
    }
};