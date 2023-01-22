//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    typedef long long ll;
    typedef pair<long long,long long> ppl;
    int countPaths(int n, vector<vector<int>>& roads) {
        int mod = 1e9+7;
        vector<ll> dist(n,INT_MAX);
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
            int node = pq.top().second;
            int dis = pq.top().first;
            pq.pop();
            
            for(auto it:adj[node]){
                int adjNode = it.first;
                int edgeWeight = it.second;
                
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

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends