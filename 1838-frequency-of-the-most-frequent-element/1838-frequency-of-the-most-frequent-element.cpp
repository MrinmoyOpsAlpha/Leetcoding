class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(begin(nums),end(nums));
        int l = 0, r= 0, res = 0;
        long long total = 0;
        int n = nums.size();
        
        while(r<n){
            total = total + nums[r];
            
            while((long)(r-l+1)*nums[r] > total + k){
                total = total - nums[l];
                l++;
            }
            res = max(res,r-l+1);
            r++;
        }
        return res;
    }
};