class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n+1,INT_MAX);
        vector<pair<int,int>> adj[n + 1];
        for(auto it:times){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adj[u].push_back({v,wt});
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        dist[k] = 0;
        pq.push({0,k});
        
        while(!pq.empty()){
            int node = pq.top().second;
            int dis = pq.top().first;
            pq.pop();
            
            for(auto it:adj[node]){
                int adjNode = it.first;
                int edgeWeight = it.second;
                
                if(dis + edgeWeight < dist[adjNode]){
                    dist[adjNode] = dis + edgeWeight;
                    pq.push({dist[adjNode],adjNode});
                }
            }
        }
        
        int time =0;
        for(int i=1;i<=n;i++){
            if(dist[i] == INT_MAX) return -1;
            time = max(time,dist[i]);
        }
        return time;
    }
};