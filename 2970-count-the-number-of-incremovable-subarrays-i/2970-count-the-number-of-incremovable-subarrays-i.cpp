class Solution {
public:
    int incremovableSubarrayCount(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int prev = 0;
                int flag = 1;
                
                for(int k=0;k<n;k++){
                    if(k<i || k>j) {
                        if(nums[k] > prev){
                            prev = nums[k];
                        }
                        else{
                            flag = 0;
                            break;
                        }
                    }
                }
                ans = ans + flag;
            }
        }
        return ans;
    }
};