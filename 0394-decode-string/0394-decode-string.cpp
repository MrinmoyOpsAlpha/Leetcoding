class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        
        for(int i=0;i<s.size();i++){
            if(s[i]!=']') st.push(s[i]);
            else{
                string temp = "";
                while(!st.empty() && st.top() != '['){
                    temp = st.top() + temp;
                    st.pop();
                }
                
                st.pop();
                
                string number = "";
                while(!st.empty() && isdigit(st.top())){
                    number = st.top() + number;
                    st.pop();
                }
                
                int k_times = stoi(number);
                while(k_times--){
                    for(int p=0;p<temp.size();p++){
                        st.push(temp[p]);
                    }
                }
            }
        }
        
        string res="";
        while(!st.empty()){
            res = st.top() + res;
            st.pop();
        }
        return res;
    }
};