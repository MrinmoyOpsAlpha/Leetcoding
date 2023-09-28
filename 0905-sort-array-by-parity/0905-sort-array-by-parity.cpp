class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        auto even = [=](int e) -> int {
            return e % 2 == 0;
        };
        
        partition(nums.begin(),nums.end(),even);
        
        return nums;
    }
};