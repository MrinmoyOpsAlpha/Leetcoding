class Solution {
    int dfs(vector<int>& nums1, vector<int>& nums2, int index, int prev1, int prev2, bool swap, map<pair<int,bool>, long long>& mp){
        if(index == nums1.size()) return 0;
        
        if(mp.find({index,swap}) != mp.end()) return mp[{index,swap}];
        
        long long take = INT_MAX, not_take = INT_MAX;
        
        // not swapped already
        if(nums1[index]> prev1 && nums2[index] > prev2)
            not_take = dfs(nums1,nums2,index + 1, nums1[index], nums2[index],false,mp);
        
        // when swapped
        if(nums1[index] > prev2 && nums2[index] > prev1)
            take = 1 + dfs(nums1,nums2,index + 1 ,nums2[index], nums1[index], true,mp);
        
        return mp[{index, swap}] = min(take,not_take);
    }
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        map<pair<int,bool>, long long> mp;
        
        return dfs(nums1, nums2, 0, -1, -1, false, mp);
    }
};
