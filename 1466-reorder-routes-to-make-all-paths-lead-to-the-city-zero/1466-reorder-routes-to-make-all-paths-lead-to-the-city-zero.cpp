class Solution {
private:
    void dfs(int currCity,vector<vector<int>>& adjCitites, vector<bool> &visited,int &count){
        visited[currCity] = true;
        for(auto city:adjCitites[currCity]){
            if(!visited[abs(city)]){
                if(city > 0) count++;
                dfs(abs(city),adjCitites,visited,count);
            } 
        }
    }
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adjCitites(n);
        vector<bool> visited(n,false);
        
        for(int i=0;i<connections.size();i++){
            int city1 = connections[i][0];
            int city2 = connections[i][1];
            
            adjCitites[city1].push_back(city2);
            adjCitites[city2].push_back(-city1);
        }
        
        int count = 0;
        dfs(0,adjCitites,visited,count);
        return count;
    }
};