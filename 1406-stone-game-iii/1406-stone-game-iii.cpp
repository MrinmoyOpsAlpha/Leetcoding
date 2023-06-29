class Solution {
    int dfs(vector<int>& stoneValue, int index, vector<int>& dp) {
        if (index >= stoneValue.size()) return 0;
        
        if (dp[index] != INT_MIN) return dp[index];
        
        int sum = 0;
        int ans = INT_MIN;
        
        for (int i = index; i < index + 3 && i < stoneValue.size(); i++) {
            sum += stoneValue[i];
            ans = max(ans, sum - dfs(stoneValue, i + 1, dp));
        }
        
        return dp[index] = ans;
    }
    
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> dp(n, INT_MIN);
        
        int aliceScore = dfs(stoneValue, 0, dp);
        
        if (aliceScore > 0)
            return "Alice";
        else if (aliceScore < 0)
            return "Bob";
        else
            return "Tie";
    }
};
