class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        int n=numCourses;
        vector<int> adj[n];
        for(auto it:prerequisites){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
        }
        
        vector<vector<bool>> table(n,vector<bool>(n,false));
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
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(auto it:adj[node]){
                table[node][it] = true;
                
                for(int i=0;i<n;i++){
                    if(table[i][node]==true) {
                        table[i][it] = 1;
                    }
                }
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }       
        
        vector<bool> ans;
        for(int i=0;i<queries.size();i++){
            bool temp = table[queries[i][0]][queries[i][1]];
            ans.push_back(temp);
        }
        return ans;
    }
};