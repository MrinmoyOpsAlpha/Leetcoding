class Solution {
    
    //using recursion
    bool recursion(vector<int>& nums,int index,int sum){
        if(sum == 0) return true;
        if(index==0) return false;
        
        if(nums[index] > sum){
            return recursion(nums,index-1,sum);
        }
        else{
            return recursion(nums,index-1,sum) || recursion(nums,index-1,sum - nums[index]);
        }
    }
    
    //using dp
    bool subset(vector<int>& nums,int n, int sum){
        int dp[n+1][sum+1];
        for(int i=0;i<n+1;i++)
            for(int j=0;j<sum+1;j++){
                if(i==0) dp[i][j] = false;
                if(j==0) dp[i][j] = true;
            }
        
        for(int i=1;i<n+1;i++)
            for(int j=1;j<sum+1;j++){
                if(nums[i-1] > j){
                    dp[i][j] = dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j] || dp[i-1][j - nums[i - 1]];
                }
            }
        return dp[n][sum];
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum%2 != 0) return false;
        return subset(nums,nums.size(),sum/2);
    }
};