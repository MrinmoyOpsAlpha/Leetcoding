class Solution {
private:
    bool canPlace(vector<int>& nums,int mid, int p){
        int cnt = 0, in = 0;
        for(int i=1;i<nums.size();i++){
            if(in){
                in = 0;
                continue;
            }
            if(nums[i] - nums[i-1] <= mid){
                in = 1;
                cnt++;
            }
        }
        return cnt >= p;
    }
public:
    int minimizeMax(vector<int>& nums, int p) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        
        int low = 0, high = nums[n-1] - nums[0];
        int ans = 0;
        while(low <= high){
            int mid = (low + high) >> 1;
            if(canPlace(nums,mid,p)){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        
        return ans;
    }
};