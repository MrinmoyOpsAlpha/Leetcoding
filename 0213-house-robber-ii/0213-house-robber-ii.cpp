class Solution {
    int maxRobbery(vector<int> temp){
        int evenAns = 0, oddAns = 0;
        for(int i =0;i<temp.size();i++){
            if(i&1) evenAns = max(evenAns + temp[i], oddAns);
            else oddAns = max(oddAns + temp[i], evenAns);
        }
        return max(oddAns,evenAns);
    }
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        if(nums.size()==1) return nums[0];
        vector<int> A(nums.begin(),nums.end()-1);
        vector<int> B(nums.begin()+1,nums.end());
        
        return max(maxRobbery(A),maxRobbery(B));
    }
};