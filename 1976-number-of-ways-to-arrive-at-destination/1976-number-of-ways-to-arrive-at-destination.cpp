class Solution {
public:
    typedef long long ll;
    typedef pair<long long,long long> ppl;
    int countPaths(int n, vector<vector<int>>& roads) {
        int mod = 1e9+7;
        vector<ll> dist(n,LLONG_MAX);
        vector<ll> ways(n,0);
        priority_queue<ppl,vector<ppl>,greater<ppl>> pq;
        dist[0] = 0;
        ways[0] = 1;
        
        //dist and node being inserted
        pq.push({0,0});
        
        vector<ppl> adj[n];
        
        for(auto it:roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        
        while(!pq.empty()){
            ll node = pq.top().second;
            ll dis = pq.top().first;
            pq.pop();
            
            for(auto it:adj[node]){
                ll adjNode = it.first;
                ll edgeWeight = it.second;
                
                //the first time the node is being visited
                if(dis + edgeWeight < dist[adjNode]){
                    dist[adjNode] = dis + edgeWeight;
                    pq.push({dist[adjNode], adjNode});
                    ways[adjNode] = ways[node];
                }
                
                //when the node is being visited for another time update the numbe of ways its being visited
                else if(dis + edgeWeight == dist[adjNode]){
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
                }
            }
        }
        return ways[n-1] % mod;
    }
};