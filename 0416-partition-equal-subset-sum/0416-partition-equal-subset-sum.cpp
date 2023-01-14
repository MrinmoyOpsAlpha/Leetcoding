class Solution {
public:
    
    int subset(vector<int> arr,int n,int w){
        int dp[n+1][w+1];
        for(int i=0;i<n+1;i++)
            for(int j=0;j<w+1;j++){
                if(i==0) dp[i][j]=0;
                if(j==0) dp[i][j]=1;
            }
        
        for(int i=1;i<n+1;i++)
            for(int j=1;j<w+1;j++){
                if(arr[i-1]>j) dp[i][j] = dp[i-1][j];
                else if(arr[i-1]<=j) dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
            }
        
        return dp[n][w];
    }
    
    bool canPartition(vector<int>& nums) {
        int sum=0;
        
        for(int i=0;i<nums.size();i++)   
            sum = sum + nums[i];
        
        if(sum%2!=0) return false;
        
        return subset(nums,nums.size(),sum/2);
    }
};