class Solution {
private:
    bool isValid(int i,int j,int m,int n){
        if(i==m||j==n||j<0||i<0)
            return false;
        return true;
    }
    
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>> dir={{1,0},{0,1},{0,-1},{-1,0}};
        queue<pair<int,int>> q;
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>> dist(m,vector<int>(n,-1));
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++)
            {
                if(mat[i][j]==0)
                { 
                    q.push({i,j});
                    dist[i][j]=0;
                }
            }
        }
        
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            
            for(auto x:dir){
                int new_i =curr.first + x[0];
                int new_j = curr.second + x[1];
                
                if(isValid(new_i,new_j,m,n) && dist[new_i][new_j] == -1){
                    q.push({new_i,new_j});
                    dist[new_i][new_j] = 1 + dist[curr.first][curr.second];
                }
            }
        }
        return dist;
    }
};