class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int n = rowIndex;

        vector<vector<int>> ans(n + 1);

        for (int i = 0; i <= n; i++) { 
            ans[i] = vector<int>(i + 1, 1);
            for (int j = 1; j < i; j++) {
                ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];
            }
        }

        vector<int> res(ans[n].begin(), ans[n].end());
        return res;
    }
};
