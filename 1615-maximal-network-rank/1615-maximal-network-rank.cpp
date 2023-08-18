class Solution {
private:
    bool checkConnection(vector<int> &adj, int i){
        for(auto node:adj){
            if(node == i) return true;
        }
        return false;
    }
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> adj[n];
        vector<int> indegree(n,0);
        
        for(auto it:roads){
            adj[it[1]].push_back(it[0]);
            adj[it[0]].push_back(it[1]);
            indegree[it[0]]++;
            indegree[it[1]]++;
        }      
        
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int temp = indegree[i] + indegree[j];
                temp = (checkConnection(adj[i],j) == 1) ? temp - 1 : temp;
                ans = max(ans,temp);
            }
        }
        
        return ans;
    }
};