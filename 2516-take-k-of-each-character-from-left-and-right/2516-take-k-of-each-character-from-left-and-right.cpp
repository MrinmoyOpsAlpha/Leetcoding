class Solution {
public:
   
    int takeCharacters(string s, int k) {
        int n = s.size();
        int ans = INT_MIN;
        int a=0,b=0,c=0;
        
        for(auto ch:s){
            if (ch=='a') a++;
            else if(ch == 'b') b++;
            else c++;
        }
        
         if(a < k || b < k || c < k)return -1;
        
        int A= a-k, B=b-k, C=c-k;
        int j = 0 , i=0;
        int ct_A = 0, ct_B = 0, ct_C = 0;
        
        while(j<s.size()){
            if(s[j]=='a') ct_A++;
            else if(s[j] == 'b')ct_B++;
            else ct_C++;
            
            while(i<=j &&  (ct_A > A || ct_B > B || ct_C > C)){
                if(s[i] == 'a')ct_A--;
                else if(s[i] == 'b')ct_B--;
                else ct_C--;
                i++;
            }
            ans = max(ans,j-i+1);
            j++;
        }
        return n-ans;
    }
};