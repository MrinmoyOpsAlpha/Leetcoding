class Solution {
    int maxRobbery(vector<int> temp){
        int rob1 = 0, rob2 = 0;
        
        for(int i=0;i<temp.size();i++){
            int curr = max(rob1 + temp[i], rob2);
            rob1 = rob2;
            rob2 = curr;           
        }
        
        return rob2;
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