class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int totalSum = 0;
        int count = 0;
        
        map<int,int> mp;
        mp[0] = 1;
        
        for(int i=0;i<nums.size();i++){
            totalSum += nums[i];
            int find = totalSum - k;
            if(mp.find(find) != mp.end())   count = count + mp[find];
            
            mp[totalSum]++;
        }
        return count;
    }
};