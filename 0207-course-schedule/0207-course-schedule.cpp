class Solution {
public:
    int count;
    vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> ans,indegree(V,0);
	    queue<int> q;
	    for(int i=0;i<V;i++){
	        for(auto it:adj[i]){
	            indegree[it]++;
	        }
	    }
	    
	    for(int i=0;i<V;i++)
	        if(indegree[i]==0)
            {
                q.push(i);
                count--;
            }
	            
	   while(!q.empty()){
	       int node = q.front();
	       q.pop();
	       
	       ans.push_back(node);
	       for(auto x:adj[node]){
	           indegree[x]--;
	           if(indegree[x]==0){
	               q.push(x);
                   count--;
	           }
	       }
	   }
	   return ans;
	}
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];        
        for(auto curr:prerequisites){
            adj[curr[1]].push_back(curr[0]);
        }
        
        count = numCourses;
        vector<int> ans = topoSort(numCourses,adj);
        return count == 0;

    }
};