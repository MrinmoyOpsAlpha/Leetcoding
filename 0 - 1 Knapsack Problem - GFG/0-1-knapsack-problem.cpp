//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    
    int help(int weight[], int val[], int cap, int i, int n, vector<vector<int>>& dp){
        if(i >= n || cap <= 0){
            return 0;
        }
        if(dp[i][cap] != -1){
            return dp[i][cap];
        }
        if(weight[i] <= cap){
            return dp[i][cap] = max(val[i] + help(weight, val, cap-weight[i], i+1, n, dp), help(weight, val, cap, i+1, n, dp));
        }
        else{
            return dp[i][cap] = help(weight, val, cap, i+1, n, dp);
        }
    }
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int subset(int w, int wt[], int val[], int n){
        int dp[n+1][w+1];
        
        for(int i=0;i<n+1;i++)
            for(int j=0;j<w+1;j++){
                if(i==0) dp[i][j] = 0;
                if(j==0) dp[i][j] = 0;
            }
            
        for(int i=1;i<n+1;i++)
            for(int j=1;j<w+1;j++){
               if(wt[i-1] <=j){
                   dp[i][j] = max(val[i-1] + dp[i-1][j-wt[i-1]],dp[i-1][j]);
               }
               else{
                   dp[i][j] = dp[i-1][j];
               }
            }
        
        return dp[n][w];
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       return subset(W,wt,val,n);
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends