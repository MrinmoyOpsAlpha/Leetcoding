class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        if(nums.size()==1) return nums[0];
        vector<int> A(nums.begin(),nums.end()-1);
        vector<int> B(nums.begin()+1,nums.end());
        
        return max(maxRobbery(A),maxRobbery(B));
    }
    
    int maxRobbery(vector<int> temp){
        int a=0,b=0,res=0;
        
        for(int i=0;i<temp.size();i++){
            res=max(b+temp[i],a);
            b=a;
            a=res;
        }
        return res;
    }
};