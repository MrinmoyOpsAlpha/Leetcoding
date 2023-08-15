//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	
	int findMaximum(int nums[], int n) {
        if(n==1) return 0;
        if(nums[0] > nums[1]) return nums[0];
        if(nums[n-1] > nums[n-2]) return nums[n-1];
        
        int low = 1,high = n-2;
        
        while(low <= high){
            int mid = (low + high) >> 1;
            if(nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]){
                return nums[mid];
            }
            else if(nums[mid] > nums[mid - 1]) low = mid + 1;
            else high = mid;
        }
        return -1;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaximum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends