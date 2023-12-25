class Solution {
private:
    void bfs(unordered_map<char,vector<pair<char,int>>> &graph, char source, vector<vector<int>>& distance){
        priority_queue<pair<int,int>> q;
        q.push({source,0}); //source, weight
        
        while(!q.empty()){
            int node = q.top().first;
            int dist = q.top().second;
            q.pop();
            
            for(auto it: graph[node]){
                if(distance[source - 'a'][it.first - 'a'] > dist + it.second){
                    distance[source - 'a'][it.first - 'a'] = dist + it.second;
                    q.push({it.first, dist + it.second});
                }
            }
        }
        return ;
    }
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        unordered_map<char,vector<pair<char,int>>> graph;
        for(int i=0;i<original.size();i++){
            graph[original[i]].push_back({changed[i],cost[i]});
        }
        
        vector<vector<int>> distance(26, vector<int>(26, INT_MAX));
        
        for(auto it:original){
            bfs(graph, it, distance);
        }
        
        long long ans = 0;
        for(int i=0;i<source.size();i++){
            if(source[i] == target[i]) continue;
            if(distance[source[i]-'a'][target[i] - 'a'] == INT_MAX) return -1;
            else{
                ans += distance[source[i] - 'a'][target[i] - 'a'];
            }
        }
        
        return ans;
    }
};