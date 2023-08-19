class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
         vector<int> adj[n];
        
        for(int i=0;i<n;i++){
            if(manager[i] != -1)
                adj[manager[i]].push_back(i);
        }
        
        queue<pair<int,int>> q;
        q.push({headID,0}); // head,time required to pass message
        int ans = 0;
        
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            auto u = node.first;
            auto w = node.second;
            
            ans = max(ans,w);
            for(auto it:adj[u]){
                q.push({it, w + informTime[u]});
            }
        }
        
        return ans;
    }
};