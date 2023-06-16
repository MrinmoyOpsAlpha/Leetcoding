class Solution {
    long long recursion(vector<vector<int>>& questions, long long index, vector<long long> &dp){
        if(index >= questions.size()) return 0;
        
        if(dp[index] != -1) return dp[index];
        
        dp[index] = max(recursion(questions,index + 1, dp), questions[index][0] + recursion(questions,index + 1 + questions[index][1], dp));
        
        return dp[index];
    }
public:
    long long mostPoints(vector<vector<int>>& questions) {
        vector<long long> dp(questions.size(), -1);
        
        return recursion(questions,0,dp);
    }
};