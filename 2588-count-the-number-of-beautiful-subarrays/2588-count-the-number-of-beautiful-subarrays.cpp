class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixXor(n+1,0);
        
        for(int i=0;i<n;i++){
            prefixXor[i+1] = prefixXor[i] ^ nums[i];
        }
        
        unordered_map<int,int> mp;
        mp[0] = 1;
        
        long long ans = 0;
        for(int i=1;i<=n;i++){
            if(mp.find(prefixXor[i]) != mp.end()) ans += mp[prefixXor[i]];
            mp[prefixXor[i]]++;
        }
        
        return ans;
    }
};