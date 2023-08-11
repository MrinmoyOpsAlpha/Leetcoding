class Solution {
private:
    int solve(vector<vector<int>>& piles, int index, int count, vector<vector<int>>& dp) {
        if (index >= piles.size() || count == 0) return 0;
        
        if (dp[index][count] != -1) return dp[index][count];
        
        // Not take
        int ans = solve(piles, index + 1, count, dp);
        
        // Take
        int size = piles[index].size() - 1;
        int sum = 0;
        for (int i = 0; i <= min(count - 1, size); i++) {
            sum += piles[index][i];
            ans = max(ans, sum + solve(piles, index + 1, count - (i + 1), dp));
        }
        return dp[index][count] = ans;
    }
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        vector<vector<int>> dp(piles.size(), vector<int>(k + 1, -1));
        return solve(piles, 0, k, dp);
    }
};
