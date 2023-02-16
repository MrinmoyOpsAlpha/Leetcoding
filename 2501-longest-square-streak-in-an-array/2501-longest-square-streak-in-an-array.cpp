class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        set<int> st(nums.begin(),nums.end());
        int ans = INT_MIN;
        int n = nums.size();
        for(int i=0;i<n;i++){
            int count = 0;
            long long int temp = nums[i];
            while(st.find(temp) != st.end()){
                count++;
                st.erase(temp);
                temp = temp * temp;
            }
            ans = max(ans,count);
        }
        return ans < 2 ? -1:ans;
    }
};