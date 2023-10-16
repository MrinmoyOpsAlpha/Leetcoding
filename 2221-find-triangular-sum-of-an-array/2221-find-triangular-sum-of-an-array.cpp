class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        
        ans.push_back(nums);
        
        for(int i=1;i<n;i++){
            vector<int> col(n-i);
            ans.push_back(col);
            for(int j=0;j<n-i;j++){
                ans[i][j] = (ans[i-1][j] + ans[i-1][j+1]) % 10;
            }
        }
        
        return ans[n-1][0];
    }
};