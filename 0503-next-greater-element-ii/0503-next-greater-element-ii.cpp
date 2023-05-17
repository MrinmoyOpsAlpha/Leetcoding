class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> res;
        
        for(int i=2*n-1 ; i>=0; i--){
            while(!st.empty() && st.top() <= nums[i%n]){
                st.pop();
            }
            
            if(i<n){
                if(!st.empty()){
                    res.push_back(st.top());
                }
                else{
                    res.push_back(-1);
                }
            }
            st.push(nums[i%n]);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};