class Solution {
public:
    int lcs(string& x,string& y,int m,int n){
        int t[m+1][n+1];
        for(int i=0;i<m+1;i++)
            for(int j=0;j<n+1;j++)
                if(i==0 || j==0) t[i][j]=0;
        
        for(int i=1;i<m+1;i++)
            for(int j=1;j<n+1;j++)  
            {
                if(x[i-1]==y[j-1]){
                    t[i][j]= 1 + t[i-1][j-1];
                }
                
                else{
                    t[i][j] = max(t[i-1][j],t[i][j-1]);
                }
            }
        return t[m][n];
    }    
    int minDistance(string word1, string word2) {
        int res=lcs(word1,word2,word1.size(),word2.size());
        
        return word1.size()-res + word2.size()-res;
    }
};