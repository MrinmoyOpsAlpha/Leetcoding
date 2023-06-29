class Solution {
public:
    // For retrieving the sum of piles between l to r
    int get(int l, int r, map<int, long long>& pref) {
        return pref[r + 1] - pref[l];
    }

    int help(int idx, int m, bool aliceTurn, map<int, long long>& pref, vector<int>& piles, map<int, map<int, map<int, int>>>& dp) {
        if (idx >= piles.size())
            return 0;

        if (dp[idx][m][aliceTurn] != -1)
            return dp[idx][m][aliceTurn];

        // At alice turn maximize the answer 
        if (aliceTurn) {
            int ans = 0;
            for (int x = 1; x <= 2 * m; x++)
                if (idx + x - 1 < piles.size())
                    ans = max(ans, get(idx, idx + x - 1, pref) + help(idx + x, max(m, x), false, pref, piles, dp));

            return dp[idx][m][aliceTurn] = ans;
        }

        // while at bob's turn minimize the answer
        int ans = 1e9;
        for (int x = 1; x <= 2 * m; x++)
            if (idx + x - 1 < piles.size())
                ans = min(ans, help(idx + x, max(m, x), true, pref, piles, dp));

        return dp[idx][m][aliceTurn] = ans;
    }

    int stoneGameII(vector<int>& piles) {
        int n = piles.size();

        map<int, long long> pref;
        pref[0] = 0;
        for (int i = 1; i <= n; i++)
            pref[i] = pref[i - 1] + piles[i - 1];

        map<int, map<int, map<int, int>>> dp;
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= 2 * n + 1; j++)
                for (int k = 0; k <= 1; k++)
                    dp[i][j][k] = -1;

        return help(0, 1, true, pref, piles, dp);
    }
};