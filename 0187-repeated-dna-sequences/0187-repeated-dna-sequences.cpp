class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        map<string,int> mp;
        int i = 0, j=0;
        string word = "";
        
        while(j<s.size()){
            word = word + s[j];
            if(j-i+1 < 10) j++;
            else{
                mp[word]++;
                word = word.substr(1);
                i++;
                j++;
            }
        }
        
        vector<string> res;
        for(auto it:mp){
            if(it.second > 1) res.push_back(it.first);
        }
        return res;
    }
};