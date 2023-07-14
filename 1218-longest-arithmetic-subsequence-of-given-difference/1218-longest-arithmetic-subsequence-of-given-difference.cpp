class Solution {
    int solve(vector<int>& arr, int difference, int index, int prev) {
        if (index >= arr.size()) return 0;
        
        int take = 0, not_take = 0;
        
        if (prev == INT_MIN) {
            take = 1 + solve(arr, difference, index + 1, arr[index]);
            not_take = solve(arr, difference, index + 1, arr[index]);
        }
        else {
            if (prev + difference == arr[index]) {
                take = 1 + solve(arr, difference, index + 1, arr[index]);
            }
            
            not_take = solve(arr, difference, index + 1, prev);
        }
        
        return max(take, not_take);
    }
    
    
    //using dp
    int longestSubsequenceDP(vector<int>& arr, int difference) {
        unordered_map<int, int> dp;
        int maxLength = 1;
        for (int i = 0; i < arr.size(); i++) {
            int curr = arr[i];
            if (dp.find(curr - difference) != dp.end()) {
                dp[curr] = dp[curr - difference] + 1;
            }
            else {
                dp[curr] = 1;
            }
            maxLength = max(maxLength, dp[curr]);
        }
        return maxLength;
    }
    
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        return longestSubsequenceDP(arr, difference);
    }
};
