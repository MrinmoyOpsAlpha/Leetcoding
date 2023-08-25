class Solution {
private:
    bool check(vector<int> adj[],int start,int n,vector<int>& color){
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
        int n = graph.size();
        vector<int> adj[n];
        vector<int> color(n,-1);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<graph[i].size();j++){
                adj[i].push_back(graph[i][j]);
                adj[graph[i][j]].push_back(i);
            }
        }
        
        for(int i=0;i<n;i++){
            if(color[i] == -1){
                if(check(adj,i,n,color) == false)
                    return false;
            }
        }
        
        return true;
    }
};