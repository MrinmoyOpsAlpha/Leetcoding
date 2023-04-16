class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adjList[numCourses];
        for(auto it:prerequisites){
            adjList[it[1]].push_back(it[0]);
        }
        
        vector<int> indegree(numCourses,0), ans;
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            for(auto it:adjList[i]){
                indegree[it]++;
            }
        }
        
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            ans.push_back(node);
            for(auto x:adjList[node]){
                indegree[x]--;
                if(indegree[x]==0){
                    q.push(x);
                }
            }
        }
        
        if(ans.size()!=numCourses) ans.clear();
        return ans;
    }
};