class Solution {
public:
    int bsearch(int target, vector<int> arr, int left=0) {
        int right = arr.size() - 1;
        while (left <= right) {
            int mid = (left + right) >> 1;
            if (arr[mid] < target) left = mid + 1;
            else right = mid - 1;
        }
        return left;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        int Tleft = bsearch(target, nums);
        vector<int> ans(2,-1);
        if (Tleft == nums.size() || nums[Tleft] != target) return ans;
        return {Tleft, bsearch(target+1, nums, Tleft) -1};
    }
};