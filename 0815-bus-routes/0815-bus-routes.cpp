class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        unordered_map<int, vector<int>> to_routes;
        for (int i = 0; i < routes.size(); ++i)
            for (int j : routes[i])
                to_routes[j].push_back(i);
        
        queue<pair<int, int>> q; // bus_stop, bus count
        q.push({source,0});
        
        unordered_set<int> seen;
        seen.insert(source);
        
        while(!q.empty()){
            int stop = q.front().first;
            int count = q.front().second;
            q.pop();
            
            if(stop == target) return count;
            
            for (auto i:to_routes[stop]){
                for(auto j:routes[i]){
                    if(seen.find(j) == seen.end()){
                        seen.insert(j);
                        q.push({j, count + 1});
                    }
                }
                routes[i].clear();
            }
        }
        
        return -1;
    }
};