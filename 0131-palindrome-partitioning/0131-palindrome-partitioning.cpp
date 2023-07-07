class Solution {
private:
    void partition(string &s, vector<vector<string>> &ans,vector<string> temp, int start){        
        if(start == s.size()){
            ans.push_back(temp);
        }
        else{
            for(int i = start;i<=s.size();i++){
                if(isPalindrome(s,start,i)){
                    temp.push_back(s.substr(start,i-start+1));
                    partition(s,ans,temp,i+1);
                    temp.pop_back();
                }
            }
        }
    }
    
    bool isPalindrome(string &s, int i, int j){
        while(i<j) {
            if(s[i++] != s[j--])
                return false;
        }
        return true;
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        partition(s,ans,temp,0);
        return ans; 
    }
};