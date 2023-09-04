class Solution {
    int helper(vector<int>& nums,int ind,int prev_ind){
        if(ind == nums.size()-1) return 0;
        int len = helper(nums,ind+1,prev_ind);
        
        if(prev_ind == -1 || nums[ind] > nums[prev_ind]){
            len = max(len,helper(nums,ind + 1, ind));
        }
        
        return len;
    }
public:
    int lengthOfLIS(vector<int>& nums) {        
        int n = nums.size();
        vector<int> dp(n,1);

        for(int i=0;i<n;i++)
            for(int j=0;j<i;j++){
                if(nums[i] > nums[j] && 1 + dp[j] > dp[i]){
                    dp[i] = dp[j] + 1;
                }
            }

        int cnt = INT_MIN;
        for(int i=0;i<n;i++){
            cnt = max(cnt,dp[i]);
        }
        return cnt;            
    }
};

