class Solution {
public:
    int lengthOfLastWord(string s) {
        int last=s.size()-1,count=0;
        
        while(last>=0 and s[last]==' '){
            last--;
        }
         while(last>=0 and s[last]!=' '){
             last--;
             count++;
         }
        return count;
    }
};