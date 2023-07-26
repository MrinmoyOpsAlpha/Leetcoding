//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int maxSubStr(string str){
        int count_0 = 0, count_1 = 0, cnt = 0;
        
        for(auto it:str){
            if(it == '0') count_0++;
            else if(it == '1') count_1++;
            if(count_0 == count_1) cnt++;
        }
        
        return (count_0 == count_1) ? cnt : -1;
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin >> str;
	    Solution ob;
	    int ans = ob.maxSubStr(str);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends