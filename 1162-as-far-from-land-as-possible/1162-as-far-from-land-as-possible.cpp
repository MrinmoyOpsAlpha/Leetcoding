class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        vector<vector<int>> directions = {{0,1},{0,-1},{1,0},{-1,0}};
        queue<pair<int,int>> q;
        int steps=0,r=grid.size(),c=grid[0].size();
        
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++){
                if(grid[i][j] == 1){
                    q.push({i,j});
                }
            }
        
        while(!q.empty()){
            int size = q.size();
            steps++;
            for(int i=0;i<size;i++){
                auto node = q.front();
                q.pop();
                int x = node.first, y = node.second;
                for(auto it:directions){
                    int nx = x + it[0];
                    int ny = y + it[1];
                    
                    if(nx>=0 && nx<r && ny>=0 && ny<c && grid[nx][ny] == 0) {
                        q.push({nx,ny});
                        grid[nx][ny] = 1;
                    }
                }
            }
        }
        return steps==1?-1:steps-1;
    }
};