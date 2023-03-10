class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        for(auto it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        
        vector<int> dist(n,INT_MAX);
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{src,0}});
        
        while(!q.empty()){
            int stop = q.front().first;
            int node = q.front().second.first;
            int cost = q.front().second.second;
            q.pop();
            
            if(stop > k) continue;
            for(auto it:adj[node]){
                int edW = it.second;
                int adjNode = it.first;
                
                if(edW + cost < dist[adjNode] && stop <= k ){
                    dist[adjNode] = edW + cost;
                    q.push({stop+1,{adjNode,dist[adjNode]}});
                }
            }
        }
        
        return (dist[dst] == INT_MAX) ? -1 : dist[dst];
    }
};