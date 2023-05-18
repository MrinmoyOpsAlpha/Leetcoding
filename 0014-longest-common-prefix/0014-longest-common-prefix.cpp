class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = strs[0];
        int charIndex = 0;
        int maxCharIndex = strs[0].length();
        
        for(int i=1;i<strs.size();i++){
            if(strs[i].size() < maxCharIndex){
                maxCharIndex = strs[i].size();
            }
        }
        
        while(charIndex < maxCharIndex){
            char prevChar = strs[0][charIndex];
            for(int i=1;i<strs.size();i++){
                if(prevChar == strs[i][charIndex]){
                    continue;
                }
                return res.substr(0,charIndex);
            }
            ++charIndex;
            res = res + prevChar;
        }
        
        return res.substr(0,charIndex);
    }
};