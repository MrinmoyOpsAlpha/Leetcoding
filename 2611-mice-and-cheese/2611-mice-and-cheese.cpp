class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        priority_queue<int> pq;
        int ans = 0;
        
        for(int i=0;i<reward1.size();i++){
            pq.push(reward1[i] - reward2[i]);
            ans += reward2[i];
        }
        
        while(k--){
            ans += pq.top();
            pq.pop();
        }
        
        return ans;
    }
};