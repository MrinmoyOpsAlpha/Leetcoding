class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if(nums.size() <= 1) return nums.size();
        int maxLength = 1;
        int ans = 0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i] < nums[i+1]){
                maxLength++;
            }
            else{
                maxLength = 1;
            }
            ans = max(ans,maxLength);
        }
        
        return ans;
    }
};