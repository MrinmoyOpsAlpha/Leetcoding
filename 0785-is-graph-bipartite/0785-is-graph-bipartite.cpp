class Solution {
private:
    bool check(int start,int V,vector<int> adj[], vector<int>& color){
        queue<int> q;
        q.push(start);
        color[start] = 0;
        
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            
            for(auto it:adj[node]){
                if(color[it] == -1){
                    color[it] = !color[node];
                    q.push(it);
                }
                else if(color[it] == color[node]){
                    return false;
                }
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> adj[V];
        vector<int> color(V,-1);
        
        for(int i=0;i<V;i++){
            for(int j=0;j<graph[i].size();j++){
                adj[i].push_back(graph[i][j]);
                adj[graph[i][j]].push_back(i);
            }
        }
        
        for(int i=0;i<V;i++){
            if(color[i] == -1){
                if(check(i,V,adj,color) == false)
                    return false;
            }
        }
        
        return true;
    }
};