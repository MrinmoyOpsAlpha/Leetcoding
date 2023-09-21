class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        
        int pairSum = 0;
        int i=0, j = nums.size()-1;
        
        while(i<=j){
            pairSum = max(pairSum,nums[i] + nums[j]);
            i++,j--;
        }
        
        return pairSum;
    }
};