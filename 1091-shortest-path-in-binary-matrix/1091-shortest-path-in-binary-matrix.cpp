class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int rows = grid.size();
        if (rows == 0) return -1;
        int cols = grid[0].size();
        if (cols == 0 ) return -1;
        if (grid[0][0] != 0 || grid[rows-1][cols-1] != 0) return -1;

        queue<pair<int,int>> q;
        q.push({0,0});
        vector<vector<int>> directions = {{1,1}, {0,1},{1,0},{0,-1},{-1,0},{-1, -1},{1, -1},{-1, 1}};

        grid[0][0] = 1;
        while(!q.empty()){
            auto node = q.front();
            q.pop();

            int x = node.first, y = node.second;

            if(x==rows-1 && y==cols-1) return grid[x][y];

            for(auto dir:directions){
                int curr_x = x + dir[0];
                int curr_y = y + dir[1];

                if(curr_x>=0 && curr_x<rows && curr_y>=0 && curr_y<cols && grid[curr_x][curr_y]==0) {
                    q.push({curr_x,curr_y});
                    grid[curr_x][curr_y] = grid[x][y] + 1;
                }
            }
        }
        return -1;
    }
};
