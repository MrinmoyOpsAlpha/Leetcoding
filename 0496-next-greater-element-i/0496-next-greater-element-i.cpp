class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> res;
        stack<int> st;
        
        int n = nums2.size();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top() < nums2[i]){
                st.pop();
            }
            
            if(!st.empty() && st.top() > nums2[i]){
                res[nums2[i]] = st.top();
            }
            else{
                res[nums2[i]] = -1;
            }
            
            st.push(nums2[i]);
        }
        
        vector<int> ans;
        for(auto x:nums1){
            ans.push_back(res[x]);
        }
        return ans;
    }
};