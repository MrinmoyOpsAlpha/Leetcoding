class Solution {
    int dp[100001];
    bool solve(vector<int>& nums,int index){
        if(index == nums.size()) return true;
        if(dp[index] != -1) return dp[index];
        
        if(index + 1 < nums.size() && nums[index] == nums[index + 1]) {
            if(solve(nums,index + 2)) return true;
            if(index + 2 < nums.size() && nums[index] == nums[index + 2]){
                if(solve(nums,index + 3)) return true;
            }
        }
        
        if(index + 2 < nums.size() && nums[index] == nums[index+1] - 1 && nums[index] == nums[index+2] - 2){
            if(solve(nums,index+3)) return true;
        }
        
        return dp[index] = false;
    }
public:
    bool validPartition(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return solve(nums, 0);
    }
};