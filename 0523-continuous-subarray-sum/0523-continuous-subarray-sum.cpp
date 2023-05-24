class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        mp[0] = -1;
        
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            sum = sum + nums[i];
            
            if(k != 0){
                sum = sum % k;
            }
            
            if(mp.count(sum) > 0){
                if(i-mp[sum] >= 2) return true;
            }
            else{
                    mp[sum] = i;
                }
        }
        return false;
    }
};