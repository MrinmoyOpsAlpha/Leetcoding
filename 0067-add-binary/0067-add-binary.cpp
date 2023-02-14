class Solution {
public:
    string addBinary(string a, string b) {
        string s;
        
        int i=a.size()-1,j=b.size()-1;
        int carry = 0;

        while(i>=0 || j>=0 || carry!=0){
            if(i>=0){
                carry += a[i] == '0' ? 0:1;
                i--;
            }
            
            if(j>=0){
                carry += b[j] == '0' ? 0:1;
                j--;
            }
            s = ((carry%2)==0 ? "0":"1") + s;
            carry /=2 ;
        }
        return s;
    }
};