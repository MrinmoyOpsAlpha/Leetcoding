class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<long long> pq;
        for(auto it:nums){
            pq.push(it);
        }
        
        long long score = 0;
        while(!pq.empty() && k--){
            int top = pq.top();
            pq.pop();
            score += top;
            pq.push(ceil(top * 1.0/3.0));
        }        
        return score;
    }
};