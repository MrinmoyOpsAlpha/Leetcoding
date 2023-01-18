class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
   
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
     
        vector<int> dp(n, 1), child(n, -1);
        
        int imax = 0;
        
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {                
                if(nums[i] % nums[j] == 0) {
                    if(1 + dp[j] > dp[i]) {
                        dp[i] = 1 + dp[j];                        
                        child[i] = j;
                    }
                }
            }
            
            if(dp[i] > dp[imax]) {
                imax = i;
            }
        }
        
        vector<int> ans;
        
        while(imax != -1) {
            ans.push_back(nums[imax]);
            imax = child[imax];
        }
        
        return ans;
    }
};