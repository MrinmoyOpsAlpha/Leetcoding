class Solution {
public:
    int ans = INT_MIN;
    
    bool isPalindrome(string &s){
        int left = 0;
        int right = s.size()-1;
        
        while(left<right){
            if(s[left++]!=s[right--]) return false;
        }
        return true;
    }
    
    void generateAll(int idx, string &s1,string &s2, string &s){
        
        if(idx >= s.length()){
            if(isPalindrome(s1) && isPalindrome(s2)){
                int l = s1.length() * s2.length();
                ans = max(ans,l);
            }
            return ;
        }
        
        char c = s[idx];
        
        s1.push_back(c);
        generateAll(idx+1,s1,s2,s);
        s1.pop_back();
        
        s2.push_back(c);
        generateAll(idx+1,s1,s2,s);
        s2.pop_back();
        
        generateAll(idx+1,s1,s2,s);
    }
    
    int maxProduct(string s) {
        string s1="";
        string s2="";
        int idx = 0;
        generateAll(idx,s1,s2,s);
        return ans;
    }
};