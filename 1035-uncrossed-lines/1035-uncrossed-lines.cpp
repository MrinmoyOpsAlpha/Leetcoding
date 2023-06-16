class Solution {
    int lcs(vector<int>& nums1, vector<int>& nums2,int n, int m){
        int t[n+1][m+1];
        
        for(int i=0;i<n+1;i++)
            for(int j=0;j<m+1;j++){
                if(i==0 || j==0) t[i][j] = 0;
            }
        
        for(int i=1;i<n+1;i++)
            for(int j=1;j<m+1;j++){
                if(nums1[i-1] == nums2[j-1]){
                    t[i][j] = 1 + t[i-1][j-1];
                }
                
                else{
                    t[i][j] = max(t[i-1][j], t[i][j-1]);
                }
            }
        
        return t[n][m];        
    }
    
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        return lcs(nums1,nums2,nums1.size(),nums2.size());
    }
};