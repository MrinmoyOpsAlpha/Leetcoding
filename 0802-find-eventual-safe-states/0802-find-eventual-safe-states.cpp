class Solution {
private:
    bool dfs(vector<vector<int>>& graph,vector<int> &color, int i){
        color[i] = 1;
        for(auto node:graph[i]){
            if(color[node] == 0 && dfs(graph,color,node) || color[node]==1 ){
                return true;
            }
        }
        color[i] = 2;
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> ans;
        vector<int> color(graph.size(),0);
        
        for(int i=0;i<graph.size();i++){
            if(!dfs(graph,color,i) || color[i] == 2){
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};