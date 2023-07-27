class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        int n = patience.size();
        vector<int> adj[n];
        vector<int> time(n,-1);
        
        for(auto x:edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        
        queue<int> q;
        q.push(0);
        time[0] = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(auto adjNode:adj[node]){
                if(time[adjNode] == -1){
                    time[adjNode] = time[node] + 1;
                    q.push(adjNode);
                }
            }
        }
        
        int res = 0;
        for(int i=1;i<n;i++){
            int extraLoad = (time[i] * 2 - 1) / patience[i];
            
            int lastOut = extraLoad * patience[i];
            int lastIn = lastOut + time[i]*2;
            res = max(res,lastIn);
        }
        
        return res + 1;
    }
};