class Solution {
public:
    void dfs(vector<vector<char>>& board,int i,int j,int rows,int cols){
        if(i<0 || i>=rows || j<0 || j>=cols || board[i][j]=='X' || board[i][j]=='D') return;
        if(board[i][j]=='O') board[i][j] = 'D';
        dfs(board,i+1,j,rows,cols);
        dfs(board,i-1,j,rows,cols);
        dfs(board,i,j+1,rows,cols);
        dfs(board,i,j-1,rows,cols);
    }
    
    void solve(vector<vector<char>>& board) {
        if(!board.size()) return;
        
        int rows = board.size();
        int cols = board[0].size();
        
        //check the boundaries
        //first the rows and then the columns
        
        for(int i=0;i<rows;i++){
            dfs(board,i,0,rows,cols);
            if(cols>1) dfs(board,i,cols-1,rows,cols);
        }
        
        for(int i=0;i<cols;i++){
            dfs(board,0,i,rows,cols);
            if(rows>1) dfs(board,rows-1,i,rows,cols);
        }
        
        //now check for the entire matrix
        // and convert D to O and O to X
        
        for(int i=0;i<rows;i++)
            for(int j=0;j<cols;j++){
                 if(board[i][j]=='O') board[i][j] ='X';
                 else if(board[i][j]=='D') board[i][j] = 'O';
            }
    }
};