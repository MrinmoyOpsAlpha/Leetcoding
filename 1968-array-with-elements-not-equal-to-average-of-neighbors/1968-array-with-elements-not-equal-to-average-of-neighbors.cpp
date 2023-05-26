class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), ptr = 0;
        vector<int> res(n);
        
        for(int i=0;i<n;i=i+2) res[i] = nums[ptr++];
        for(int j=1;j<n;j=j+2) res[j] = nums[ptr++];
        
        return res;
    }
};