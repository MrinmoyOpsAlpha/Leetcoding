class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<pair<int,double>> adj[n];
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        
        vector<int> seen(n, 0);
        priority_queue<pair<double, int>> q;
        q.push({(double)1.0, start});
        
        vector<double> mx(n, (double)0.0);
        mx[start] = 1.0;
        
        while(!q.empty()){
            auto top = q.top();
            q.pop();
            
            double proba = top.first;
            int node = top.second;
            
            if(!seen[node]){
                seen[node] = 1;
                for(auto it:adj[node]){
                    if(mx[it.first] < it.second * proba){
                        mx[it.first] = it.second * proba;
                        q.push({mx[it.first], it.first});
                    }
                }
            }
        }       
        return mx[end];
    }
};