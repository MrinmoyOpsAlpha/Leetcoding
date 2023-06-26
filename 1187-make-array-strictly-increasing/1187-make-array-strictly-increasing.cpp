class Solution {
private:
    int helper(int idx, int prev, vector<int> &arr1, vector<int> &arr2, map<pair<int, int>, int> &dp) {
        if(idx == arr1.size()) {
            return 0;
        }

        if(dp.find({idx, prev}) != dp.end()) {
            return dp[{idx, prev}];
        }
        int take = 1e9, not_take = 1e9;

        int i = upper_bound(arr2.begin(), arr2.end(), prev) - arr2.begin();
        if(i < arr2.size()) {
            take = 1 + helper(idx + 1, arr2[i], arr1, arr2, dp);            
        }

        if(arr1[idx] > prev) {
            not_take = helper(idx + 1, arr1[idx], arr1, arr2, dp);
        }

        return dp[{idx, prev}] = min(take, not_take);
    }
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        map<pair<int, int>, int> dp;
        sort(arr2.begin(), arr2.end());
        int res = helper(0, -1, arr1, arr2, dp);
        return res >= 1e9 ? -1 : res;
    }
};