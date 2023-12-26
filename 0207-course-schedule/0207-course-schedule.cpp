class Solution {
    int count = 0;
    vector<int> topoSort(int V,vector<int> adj[]){
        vector<int> ans(V), indegree(V,0);
        queue<int> q;
        
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                indegree[it]++;
            }
        }
        
        for(int i=0;i<V;i++){
            if(indegree[i] == 0){
                q.push(i);
                count--;
            }
        }
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                    count--;
                }
            }
        }
        
        return ans;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        
        for(auto it: prerequisites){
            adj[it[0]].push_back(it[1]);
        }
        
        count = numCourses;
        vector<int> res = topoSort(numCourses,adj);
        return count == 0;
    }
};