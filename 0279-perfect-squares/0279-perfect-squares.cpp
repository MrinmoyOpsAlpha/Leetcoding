class Solution {
    int subset(vector<int> &squares, int n,int w){
        int t[n+1][w+1];
        for(int i=0;i<n+1;i++)
            for(int j=0;j<w+1;j++){
                if(i==0) t[i][j] = INT_MAX - 1;
                if(j==0) t[i][j] = 0;
            }
        
        for(int i=1;i<n+1;i++)
            for(int j=1;j<w+1;j++){
                if(squares[i-1] > j){
                    t[i][j] = 0 + t[i-1][j];
                }
                else{
                    t[i][j] = min(1 + t[i][j-squares[i-1]], 0 + t[i-1][j]);
                }
            }
        
        return t[n][w];
        
    }
public:
    int numSquares(int n) {
        vector<int> squares;
        for(int i=1;i*i<=n;i++){
            squares.push_back(i*i);
        }
        
        return subset(squares,squares.size(),n);
    }
};