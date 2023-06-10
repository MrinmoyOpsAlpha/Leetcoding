class Solution {
void bfs(vector<int> adj[],int src, vector<int>& dist){
    queue<int> q;
    q.push(src);
    dist[src] = 0;
    
    while(!q.empty()){
        auto node = q.front();
        q.pop();
        
        for(auto it:adj[node]){
            if(it != -1 && dist[it] == INT_MAX){
                q.push(it);
                dist[it] = 1 + dist[node];
            }
        }
    }
}
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> adj[n];
        
        for (int i = 0; i < n; i++) {
            adj[i].push_back(edges[i]);
        }
        
        vector<int> A(n,INT_MAX), B(n,INT_MAX);
        bfs(adj,node1,A);
        bfs(adj,node2,B);
        
        int res =INT_MAX , node = -1;
        
        for(int i = 0;i<n;i++){
            if(A[i]==INT_MAX or B[i]==INT_MAX) continue;
            if(res > max(A[i],B[i])) {
                node = i;
                res = max(A[i],B[i]);
            }
        }
        return node;
    }
};