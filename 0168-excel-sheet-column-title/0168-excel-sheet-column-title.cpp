class Solution {
public:
    string convertToTitle(int columnNumber) {
        string res;
        char tmp;
        int n=columnNumber;
        while(n){
            n=n-1;
            tmp='A' + n%26;
            cout<<tmp<<" ";
            res=tmp + res;
            n=n/26;
        }
        return res;
    }
};