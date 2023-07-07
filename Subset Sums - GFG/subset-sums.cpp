//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
    void solve(vector<int> arr, vector<int>& ans,int index,int sum){
        ans.push_back(sum);
        
        for(int i = index;i<arr.size();i++){
            sum = sum + arr[i];
            solve(arr,ans,i+1,sum);
            sum = sum - arr[i];
        }
    }
public:
    vector<int> subsetSums(vector<int> arr, int N)
    {
       vector<int> ans;
       solve(arr,ans,0,0);
       return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends