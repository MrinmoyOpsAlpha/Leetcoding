class Solution {
    private:
    int dfs(bool alice, int i, int M, vector<int>& piles, unordered_map<string, int>& dp) {
        if (i == piles.size()) {
            return 0;
        }

        string key = to_string(alice) + "-" + to_string(i) + "-" + to_string(M);
        if (dp.find(key) != dp.end()) {
            return dp[key];
        }

        int res = alice ? 0 : INT_MAX;
        int total = 0;

        for (int X = 1; X <= 2 * M; X++) {
            if (i + X > piles.size()) {
                break;
            }

            total += piles[i + X - 1];

            if (alice) {
                res = max(res, total + dfs(!alice, i + X, max(M, X), piles, dp));
            } else {
                res = min(res, dfs(!alice, i + X, max(M, X), piles, dp));
            }
        }

        dp[key] = res;
        return res;
    }
public:
    int stoneGameII(vector<int>& piles) {
        unordered_map<string, int> dp;
        return dfs(true, 0, 1, piles, dp);
    }
};