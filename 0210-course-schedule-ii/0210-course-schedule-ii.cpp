class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ans, adj[numCourses], indegree(numCourses,0);
        
        for(auto curr:prerequisites){
            adj[curr[1]].push_back(curr[0]);
        }
        
        queue<int> q;
        
        for(int i=0;i<numCourses;i++){
            for(auto it:adj[i]){
                indegree[it]++;
            }
        }
        
        for(int i=0;i<numCourses;i++){
            if(indegree[i] == 0) q.push(i);
        }
        
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            
            ans.push_back(node);
            for(auto x:adj[node]){
                indegree[x]--;
                if(indegree[x]==0)
                    q.push(x);
            }
        }
        if(ans.size()!=numCourses) ans.clear();
        return ans;
    }
};