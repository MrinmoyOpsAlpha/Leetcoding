class Solution {
    int solve(vector<int>& piles, int start, int end,vector<vector<int>>& dp){
        if(start > end) return false;
        
        if(dp[start][end] != -1) return dp[start][end];
        
        bool even = ((end - start) % 2) == 0;
        
        int left = (even == true) ? piles[start] : 0;
        int right = (even == true) ? piles[end] : 0;
        
        return dp[start][end] = max( solve(piles,start+1, end, dp) + left, solve(piles,start,end - 1, dp) + right);
    }
public:
    bool stoneGame(vector<int>& piles) {
        vector<vector<int>> dp(piles.size(), vector<int>(piles.size(),-1));
        return solve(piles,0,piles.size() - 1, dp) > accumulate(piles.begin(), piles.end(), 0) / 2;
    }
};