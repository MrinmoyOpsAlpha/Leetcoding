//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int arr[],  int n, int k) 
    { 
        unordered_map<int,int> mp;
        int sum = 0, maxLength = 0;
        
        for(int i=0;i<n;i++){
            sum += arr[i];
            if(sum == k){
                maxLength = i + 1;
            }
            
            if(mp.find(sum) == mp.end()){
                mp[sum] = i ;
            }
            
            if(mp.find(sum - k) != mp.end()){
                maxLength = max(maxLength,(i - mp[sum - k]));
            }
        }
        
        return maxLength;
    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends