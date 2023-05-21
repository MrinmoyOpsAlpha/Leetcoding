class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int,int> mp;
        for(auto it:nums) mp[it]++;
        
        int count = 0;
        
        for(int i=0;i<nums.size();i++){           
            
            if(mp.find(nums[i]-1) == mp.end()){
                int num = nums[i];
                int streak = 1;
                
                while(mp.find(num + 1) != mp.end()){
                    num = num + 1;
                    streak = streak + 1;
                }
                count = max(count,streak);
            }
        }
        return count;
    }
};