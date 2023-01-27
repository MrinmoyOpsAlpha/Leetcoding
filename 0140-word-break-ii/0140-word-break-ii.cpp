class Solution {
public:
    int n;
    set<string> st;
    vector<string> ans;
    
    void dfs(string& s,string output,int start){
        if(start==n){
            int x = output.size();
            string temp = output.substr(0,x-1);
            ans.push_back(temp);
            return;
        }
        
        if(start > n) return;
        
        for(int i=1;i<=n;i++){
            string str = s.substr(start,i);
            if(st.find(str)!=st.end()){
                string out = output + str + " ";
                dfs(s,out,start + i);
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        ans.clear();
        n = s.size();
        for(auto it:wordDict) st.insert(it);
        
        dfs(s,"",0);
        return ans;
    }
};