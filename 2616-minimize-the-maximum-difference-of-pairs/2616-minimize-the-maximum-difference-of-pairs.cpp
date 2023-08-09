class Solution {
private:
    bool canPlace(vector<int>& nums,int mid, int p){
        int cnt = 0;
        for(int i=0;i<nums.size()-1 && cnt < p;){
            if(nums[i+1] - nums[i] <= mid){
                cnt++;
                i=i+2;
            }
            else{
                i++;
            }
        }
        return cnt >= p;
    }
public:
    int minimizeMax(vector<int>& nums, int p) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        
        int low = 0, high = nums[n-1] - nums[0];
        
        while(low < high){
            int mid = (low + high) >> 1;
            if(canPlace(nums,mid,p)){
                high = mid;
            }
            else{
                low = mid + 1;
            }
        }
        
        return low;
    }
};