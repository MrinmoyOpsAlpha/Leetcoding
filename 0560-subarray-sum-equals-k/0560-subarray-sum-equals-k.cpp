class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int totalSum = 0, cnt = 0 ;
        map<int,int> mp;
        mp[0] = 1;
        
        for(int i=0;i<nums.size();i++){
            totalSum += nums[i];
            int toFind = totalSum - k;
            if(mp.find(toFind) != mp.end()) cnt = cnt + mp[toFind];
            mp[totalSum]++;
        }
        
        return cnt;
    }
};