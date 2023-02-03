class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows <= 1) return s;
        vector<string> ans(numRows,"");
        
        int rows = 0, step = -1;
        for(int i=0;i<s.size();i++){
            if(rows == 0 || rows == numRows-1 ) step = -step;
            ans[rows] = ans[rows] + s[i];
            rows = rows + step;
        }
        
        string res="";
        for(auto it:ans) res = res + it;
        return res;
    }
};