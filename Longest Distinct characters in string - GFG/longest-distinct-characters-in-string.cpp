//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int longestSubstrDistinctChars (string S);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;

        cout << longestSubstrDistinctChars (S) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends


int longestSubstrDistinctChars (string S)
{
   if(S.size() <=1) return S.size();
   
   int maxL = 0;
   bool visited[256] = {false};
   
   int l=0,r=0;
   
   while(r<S.size()){
       if(visited[S[r]] == true){
           while(visited[S[r]] == true){
               visited[S[l]] = false;
               l++;
           }
       }
       
       visited[S[r]] = true;
       maxL = max(maxL,r-l+1);
       r++;
   }
   
   return maxL;
}