class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        for(auto it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        
        vector<int> dist(n,INT_MAX);
        queue<pair<int,pair<int,int>>> q; // stops, {neighbour, dist of neighbour}
        q.push({0,{src,0}});
        
        while(!q.empty()){
            int stops = q.front().first;
            int node  = q.front().second.first;
            int cost  = q.front().second.second;
            q.pop();
            
            if(stops > k )continue;
            for(auto it:adj[node]){
                int edW = it.second;
                int adjNode = it.first;
                
                if(edW + cost < dist[adjNode] && stops <= k){
                    dist[adjNode] = edW + cost;
                    q.push({stops + 1, {adjNode, dist[adjNode]}});
                }
            }
        }
        
        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};