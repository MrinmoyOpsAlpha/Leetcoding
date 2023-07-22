class Solution {
    bool valid(int n, int row, int column) {
        return (row >= 0 && row < n && column >= 0 && column < n);
    }

public:
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<int>> dir = {{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1},{-2,1},{-1,2}};
        vector<vector<double>> dp(n, vector<double>(n));
        dp[row][column] = 1.0;
        queue<pair<int, int>> q;
        q.push({row, column});

        while (k-- && !q.empty()) {
            int size = q.size();
            vector<vector<double>> dp1(n, vector<double>(n));

            for (int i = 0; i < size; i++) {
                auto node = q.front();
                int x = node.first;
                int y = node.second;
                q.pop();

                for (auto it : dir) {
                    int x_new = x + it[0];
                    int y_new = y + it[1];
                    if (valid(n, x_new, y_new)) {
                        if (!dp1[x_new][y_new]) {
                            q.push({x_new, y_new});
                        }
                        dp1[x_new][y_new] += dp[x][y] / 8.0;
                    }
                }
            }
            dp = dp1;
        }

        double prob = 0.0;
        for (auto ans : dp) {
            for (auto it : ans) {
                prob += it;
            }
        }

        return prob;
    }
};
