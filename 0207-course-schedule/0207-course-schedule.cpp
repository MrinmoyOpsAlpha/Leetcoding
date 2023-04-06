class Solution {
public:
    
    bool isCyclic(vector<int> adj[],vector<int>& vis,int id){
        if(vis[id]==1) return true;
        
        if(vis[id]==0){
            vis[id]=1;
           
            for(auto curr:adj[id]){
                if(isCyclic(adj,vis,curr)){
                    return true;
                }
            }
        }
        vis[id]=2;
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        vector<int> vis(numCourses,0);
        
        for(auto curr:prerequisites){
            adj[curr[1]].push_back(curr[0]);
        }
        
        for(int i=0;i<numCourses;i++){
            if(isCyclic(adj,vis,i)){
                return false;
            }
        }
        return true;
        
    }
};