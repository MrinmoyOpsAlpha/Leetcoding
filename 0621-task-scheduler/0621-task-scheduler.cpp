class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> pq;
        queue<pair<int,int>> q;
        vector<int> v(26);
        
        for(int i=0;i<tasks.size();i++) v[tasks[i] - 'A']++;
        for(int i=0;i<26;i++) if(v[i]) pq.push(v[i]);
        
        int time = 0;
        while(!q.empty() || !pq.empty()){
            time++;
            if(!pq.empty()){
                if(pq.top() - 1){
                    q.push({pq.top() - 1, time + n});
                }
                pq.pop();
            }
            
            if(!q.empty() &&  q.front().second == time){
                pq.push(q.front().first);
                q.pop();
            }
        }
        
        return time;
        
    }
};