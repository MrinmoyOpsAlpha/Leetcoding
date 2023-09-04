class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0];
        int currMax = 1, currMin = 1;
        
        for(int i=0;i<nums.size();i++){
            int n = nums[i];
            int temp = currMax * n;
            currMax = max(max(n*currMax,n*currMin),n);
            currMin = min(min(temp,n*currMin),n);
            res = max(currMax,res);
        }
        return res;
    }
};