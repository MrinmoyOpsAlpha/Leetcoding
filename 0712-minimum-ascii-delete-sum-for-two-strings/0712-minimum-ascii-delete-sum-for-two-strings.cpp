class Solution {
        int lcs(string& s1, string& s2) {
        int m = s1.size();
        int n = s2.size();
        
        vector<vector<int>> t(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    t[i][j] = s1[i-1] + t[i - 1][j - 1];
                } else {
                    t[i][j] = max(t[i - 1][j], t[i][j - 1]);
                }
            }
        }

        return t[m][n];
    }

public:
    int minimumDeleteSum(string s1, string s2) {
        int common = lcs(s1, s2);
        int sum1 = 0,sum2 = 0;
        
        for (char c : s1) {
            sum1 += c;
        }

        for (char c : s2) {
            sum2 += c;
        }

        return sum1 + sum2 - 2 * common;
    }
};
