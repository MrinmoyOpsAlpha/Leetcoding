class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int n = recipes.size();
        unordered_map<string,vector<string>> graph;
        
        unordered_set<string> st;
        for(auto x:supplies) st.insert(x);
        
        unordered_map<string,int> indegree;
        for(auto x : recipes)indegree[x] = 0;       
        
        
        for(int i=0;i<n;i++){
            for(int j=0;j<ingredients[i].size();j++){
                if(st.find(ingredients[i][j])==st.end()){
                    graph[ingredients[i][j]].push_back(recipes[i]);
                    indegree[recipes[i]]++;
                }
            }
        }
        
        queue<string> q;
        for(auto x:indegree){
            if(x.second==0){
                q.push(x.first);
            }
        }
        
        vector<string> ans;
        while(!q.empty()){
            string temp = q.front();
            q.pop();
            
            ans.push_back(temp);
            for(auto it:graph[temp]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
            
        }
        return ans;
    }
};