class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;
        vector<int> ans;
        int i=0,j=0;
        while(j<nums.size()){
            pq.push({nums[j],j});
            if(j-i+1 == k ){
                while(pq.top().second < i) {
                    pq.pop();
                }
                ans.push_back(pq.top().first);
                i++,j++;
            }
            else j++;
        }
        return ans;
    }
};