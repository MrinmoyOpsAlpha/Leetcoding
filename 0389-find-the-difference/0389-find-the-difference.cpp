class Solution {
public:
    char findTheDifference(string s, string t) {
        char ch = 0 ;
        
        for(auto it:s){
            ch = ch ^ it; 
        }
        
        for(auto it:t){
            ch = ch ^ it; 
        }
        
        return ch;
    }
};