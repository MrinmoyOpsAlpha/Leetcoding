class Solution {
public:
    bool checkValidString(string s) {
        stack<int> st,asterRisk;
        
        for(int i=0;i<s.size();i++){
            auto it = s[i];
            if(it == '('){
                st.push(i);
            }
            
            else if(it == '*') {
                asterRisk.push(i);
            }
            
            else if(it == ')'){
                if(!st.empty()){
                    st.pop();
                }
                else if(!asterRisk.empty()){
                    asterRisk.pop();
                }
                else 
                    return false;
            }
        }
        
        while(!st.empty() && !asterRisk.empty()){
            if(st.top() > asterRisk.top()) return false;
            st.pop();
            asterRisk.pop();
        }
        
        return st.empty();
    }
};