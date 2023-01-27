class Solution {
public:
    bool wordCheck(string word, set<string> &st){
        for(int i=0;i<word.length();i++){
            string prefix = word.substr(0,i);
            string suffix = word.substr(i,word.length()-i);
            if(st.find(prefix)!=st.end() && (st.find(suffix)!=st.end() || wordCheck(suffix,st)) ){
                return true;
            }
        }
        return false;
    }
    
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        set<string> st;
        vector<string> ans;
        
        for(auto it:words){
            st.insert(it);
        }
        
        for(auto it:words){
            if(wordCheck(it,st)==true){
                ans.push_back(it);
            }
        }
        
        return ans;
    }
};