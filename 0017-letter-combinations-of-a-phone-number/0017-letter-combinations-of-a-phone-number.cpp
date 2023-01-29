class Solution {
public:
    map<int,string> m;
    vector<string> ans;
    
    void dfs(int start,string& digits,string &temp){
        if(start==digits.size()){
            ans.push_back(temp);
            return;
        }
        
        for(auto it:m[digits[start]-'0']){
            temp = temp + it;
            dfs(start+1,digits,temp);
            temp.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {    
        ans.clear();
        if(digits=="") return ans;
        
        m[2] = "abc";
        m[3] = "def";
        m[4] = "ghi";
        m[5] = "jkl";
        m[6] = "mno";
        m[7] = "pqrs";
        m[8] = "tuv";
        m[9] = "wxyz";
        
        string temp;
        dfs(0,digits,temp);
        return ans;
    }
};