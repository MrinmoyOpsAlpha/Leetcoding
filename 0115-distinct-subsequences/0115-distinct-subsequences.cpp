class Solution {
    int lcs(string s,string y,int m ,int n){
        double t[m+1][n+1];
        
        for(int i=0;i<m+1;i++)
            for(int j=0;j<n+1;j++){
                if(i==0) t[i][j] = 0;
                if(j==0) t[i][j] = 1;
            }
        
        for(int i=1;i<m+1;i++){
            for(int j=1;j<n+1;j++){
                if(s[i-1]==y[j-1]) t[i][j] = t[i-1][j] + t[i-1][j-1];
                
                else t[i][j] = t[i-1][j];
            }
        }
        return t[m][n];
    }
public:
    int numDistinct(string s, string t) {
        return lcs(s,t,s.size(),t.size());
    }
};