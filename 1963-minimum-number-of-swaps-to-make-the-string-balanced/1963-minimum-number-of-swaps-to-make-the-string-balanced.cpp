class Solution {
public:
    int minSwaps(string s) {
        stack<char> st;
        
        for(auto ch:s){
            if(ch == '[') st.push(ch);
            else if(!st.empty()) st.pop();
        }
        return (st.size()+1) / 2;
    }
};