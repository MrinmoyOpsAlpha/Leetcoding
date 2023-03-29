class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int,int> mp;
        for(auto it:nums) mp[it]++;
        
        int count = 0;
        
        for(auto num:nums){
            if(mp.find(num-1) == mp.end()){
                int currNum = num;
                int currStreak = 1;
                
                while(mp.find(currNum + 1) != mp.end()){
                    currNum = currNum + 1;
                    currStreak = currStreak + 1;
                }
                count = max(count,currStreak);
            }
        }
        
        return count;
    }
};