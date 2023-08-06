class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        priority_queue<double,vector<double>,greater<double>> pq;
        
        for(int i=0;i<dist.size();i++){
            pq.push(ceil((double)dist[i]/speed[i]));
        }
        
        int time = 0,ans = 0;
        while(!pq.empty()){
            if(pq.top() > time){
                pq.pop();
                ans++;
            }
            
            else break;
            time++;
        }
        
        return ans;
    }
};