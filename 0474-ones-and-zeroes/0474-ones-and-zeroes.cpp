class Solution {
    int dp[601][101][101] = {};
    
    int recursion(vector<pair<int,int>> &a, int index , int nOnes , int nZeros){
        int n = a.size();
        if(index == n or (nZeros ==0 and nOnes == 0))   return 0;
        
        if(dp[index][nOnes][nZeros] != -1)
            return dp[index][nOnes][nZeros];
        
        if(a[index].first > nOnes or a[index].second > nZeros)  
            return recursion(a , index+1 , nOnes , nZeros);
        
        int include = 1 + recursion(a , index+1, nOnes - a[index].first , nZeros - a[index].second);
        int exclude = recursion(a , index+1 , nOnes , nZeros);
        
        return dp[index][nOnes][nZeros] = max(include , exclude);
    }
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int,int>> v;
        memset(dp , -1 , sizeof(dp));
        
        for(auto str:strs){
            int ones = 0, zeros = 0;
            for(auto i:str){
                (i == '1') ? ones++ : zeros++;
            }
            v.push_back({ones,zeros});
        }
        
        int ans = recursion(v,0,n,m);
        return ans;
    }
};