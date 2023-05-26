class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        
        int res = 0, i=0, j = nums.size()-1, mod = 1e9+7, n = nums.size();
        
        vector<int> pow(n,1);
        for(int i=1;i<n;i++){
            pow[i] =( pow[i-1] * 2) % mod;
        }
        
        while(i<=j){
            if(nums[i] + nums[j] > target) j--;
            else {
                res = (res + pow[j-i]) % mod;
                i++;
            }
        }
        return res;
    }
};