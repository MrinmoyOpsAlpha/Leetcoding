class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        map<char,int> mp; // char , index
        
        
        int length = -1;
        for(int i=0;i<s.size();i++){
            if(mp.find(s[i]) != mp.end()){
                length = max(length, i - mp[s[i]] - 1);
            }
            else{
                mp[s[i]] = i;
            }
        }
        
        return length;
    }
};