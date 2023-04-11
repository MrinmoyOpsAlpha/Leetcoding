class Solution {
public:
    int rob(vector<int>& nums) {
        int oddAns=0,evenAns=0;
        
        for(int i=0;i<nums.size();i++){
            if(i & 1) evenAns = max(evenAns + nums[i] , oddAns);
            else oddAns = max(oddAns + nums[i] , evenAns);
        }
        return max(oddAns,evenAns);
    }
};