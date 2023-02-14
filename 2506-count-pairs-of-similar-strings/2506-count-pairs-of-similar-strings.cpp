class Solution {
public:
    int similarPairs(vector<string>& words) {
        int res = 0;
        vector<string> v;
        for(auto w:words){
            set<char> s;
            for(auto c:w){
                s.insert(c);
            }
            
            string t ="";
            for(auto m:s) t = t + m;
            v.push_back(t);
        }
        
        for(int i=0;i<v.size();i++){
            for(int j = i+1;j<v.size();j++){
                if(v[i]==v[j]) res++;
            }
        }
        
        return res;
    }
};