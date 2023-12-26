class Solution {
private:
    int MOD = 1e9 + 7;
    int helper(int n, int k, int num, int target, int curr, vector<vector<int>> &dp) {
        if (n == num) {
            if (target == curr) return 1;
            return 0;
        }

        if (dp[curr][num] != -1) return dp[curr][num];

        long long total = 0;
        for (int i = 1; i <= k; i++) {
            if (curr + i <= target) {
                total = (total + helper(n, k, num + 1, target, curr + i, dp)) % MOD;
            }
        }

        return dp[curr][num] = total;
    }

public:
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(target + 1, vector<int>(n + 1, -1)); // Adjust the size of dp
        return helper(n, k, 0, target, 0, dp);
    }
};
