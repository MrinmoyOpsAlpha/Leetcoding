class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<pair<int,int>> st; // value , minimum value
        int minElement = nums[0];
        for(int i = 1; i < nums.size(); i++){
            while(!st.empty() && st.top().first <= nums[i]){
                st.pop();
            }
            if(!st.empty() && nums[i] > st.top().second){
                return true;
            }
            st.push({nums[i], minElement});
            minElement = min(minElement, nums[i]);
        }
        return false;
    }
};
