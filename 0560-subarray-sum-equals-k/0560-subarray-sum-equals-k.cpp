class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int> mp;
        mp[0] = 1;
        
        int totalSum = 0;
        int cnt = 0;
        for(int i=0;i<nums.size();i++){
            totalSum += nums[i];
            
            int findNum = totalSum - k;
            
            if(mp.find(findNum) != mp.end()) cnt += mp[findNum];
            
            mp[totalSum]++;
        }
        
        return cnt;
    }
};