class Solution {
public:
    void generateParenthesis(vector<string> &ans, string s, int open, int close){
        if(open == 0 && close == 0){
            ans.push_back(s);
            return;
        }
        if(open > 0){
            s.push_back('(');
            generateParenthesis(ans,s,open-1, close);
            s.pop_back();
        }
        
        if(close > 0){
            if(close > open){
                s.push_back(')');
                generateParenthesis(ans,s,open, close-1);
                s.pop_back();
            }
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s;
        generateParenthesis(ans,s,n,n);
        return ans;
    }
};