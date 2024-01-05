class Solution {
private:
    void helper(string &temp,int open, int close, vector<string>& ans, int n){
        if(open == n && close == n){
            ans.push_back(temp);
            return;
        }
        
        if(open + 1 <= n){
            temp.push_back('(');
            helper(temp,open + 1, close,ans,n);
            temp.pop_back();
        }
        
        if(close + 1 <= n && close + 1 <= open){
            temp.push_back(')');
            helper(temp,open, close + 1,ans,n);
            temp.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string res;
        helper(res,0,0,ans,n);
        return ans;
    }
};