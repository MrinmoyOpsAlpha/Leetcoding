class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        int n = nums.size();
        
        long long cnt = 0, xr = 0;
        map<long long, long long> mp;
        mp[0] = 1;
        
        for(int i=0;i<nums.size();i++){
            xr = xr ^ nums[i];
            
            if(mp.find(xr) != mp.end()) cnt += mp[xr];
            
            mp[xr]++;
        }
        return cnt;
    }
};