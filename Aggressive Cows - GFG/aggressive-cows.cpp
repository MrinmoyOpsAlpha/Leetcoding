//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
private:
    bool canPlaceCows(vector<int> &stalls, int n, int k, int dist) {
        int co_ord = stalls[0];
        int cnt = 1; 
        for (int i = 1; i < n; i++) {
            if (stalls[i] - co_ord >= dist) {
                cnt++;
                co_ord = stalls[i];
            }

            if (cnt == k) {
                return true;
            }
        }

        return false;
    }


public:
    int solve(int n, int k, vector<int> &stalls) {
        sort(stalls.begin(), stalls.end());
        int low = 1, high = stalls[n - 1] - stalls[0];
        int res = 0;

        while (low <= high) {
            int mid = (low + high) >> 1;
            if (canPlaceCows(stalls, n, k, mid)) {
                res = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends