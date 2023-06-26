class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<int,vector<int>,greater<int>> pq1, pq2;        
        long long cost = 0;
        
        int l = 0, r = costs.size() - 1;
        
        while(k--){
            while(pq1.size() < candidates && l <= r){
                pq1.push(costs[l]);
                l++;
            }
            
            while(pq2.size() < candidates && l <= r){
                pq2.push(costs[r]);
                r--;
            }
            
            int top1 = pq1.size() > 0 ? pq1.top() : INT_MAX;
            int top2 = pq2.size() > 0 ? pq2.top() : INT_MAX;
            
            if(top1 <= top2){
                cost += top1;
                pq1.pop();
            }
            else{
                cost += top2;
                pq2.pop();
            }
        }
        
        return cost;
    }
};