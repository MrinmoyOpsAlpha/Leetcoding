class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
        }
        
        vector<int> indegree(n,0);
        queue<int> q;
        
        for(int i=0;i<n;i++){
            for(auto it:adj[i]){
                indegree[it]++;
            }
        }
        
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        
        set<int> st[n];
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(auto it:adj[node]){
                // adding parent node to child node
                st[it].insert(node);
                
                //adds all the ancestors of the current node
                for(auto it2:st[node]){
                    st[it].insert(it2);
                }
                
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        
        vector<vector<int>> ans(n,vector<int>());
        for(int i=0;i<n;++i)
            ans[i]=vector<int>(st[i].begin(),st[i].end());
        
        
        return ans;
        
    }
};