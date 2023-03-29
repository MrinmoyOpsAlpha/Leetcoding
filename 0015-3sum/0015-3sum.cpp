class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int low = i+1, high = n-1 , sum = 0 - nums[i];
            
            while(low<high){
                if(nums[low] + nums[high] == sum){
                    vector<int> quad(3,0);
                    quad[0] = nums[i];
                    quad[1] = nums[low];
                    quad[2] = nums[high];
                    ans.push_back(quad);
                    
                    while(low<high && nums[low] == nums[low+1]) low++;
                    while(low<high && nums[high] == nums[high-1]) high--;
                    low++;
                    high--;
                }
                else if(nums[low] + nums[high] < sum) low++;
                else high--;
            }
            
        }
        return ans;
    }
};