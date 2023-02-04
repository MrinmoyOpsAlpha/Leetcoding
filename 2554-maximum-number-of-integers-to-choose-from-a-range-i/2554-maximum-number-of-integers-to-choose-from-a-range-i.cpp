class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int> ban(banned.begin(), banned.end());
        int counter = 0;
        for (int i = 1; i <= n; i++) {
            if (ban.count(i)) continue;
            if (i <= maxSum) {
                counter++;
                maxSum = maxSum - i;
            }
            else break;
        }
        return counter;
    }
};