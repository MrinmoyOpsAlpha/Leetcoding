class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int w = accumulate(stones.begin(),stones.end(), 0);        
        int n = stones.size();
        
        bool dp[n+1][w+1];
        
        for (int i=0;i<n+1;i++)
            for(int j=0;j<w+1;j++){
                if(i==0) dp[i][j] = false;
                if(j==0) dp[i][j] = true;
            }
        
        for(int i=1;i<n+1;i++)
            for(int j=1;j<w+1;j++){
                if(stones[i-1] > j){
                    dp[i][j] = dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-stones[i-1]];
                }
            }
        
        int diff = INT_MAX;
        
        for (int j = w/2; j >= 0; j--)
        {
            if (dp[n][j] == true)
              diff = min(diff, w - 2*j);
        }
        
        return diff;
       
    }
};