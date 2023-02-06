class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> res(2*n);
        for(int i=0,index=0;index<2*n ; i++){
            res[index++] = nums[i];
            res[index++] = nums[i+n];
        }
        return res;
    }
};