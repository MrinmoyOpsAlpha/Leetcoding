class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        stringstream ss(s);
        int num;
        char op = '+';
        
        while(ss >> num){
            if(op == '+' || op =='-'){
                st.push(op == '+' ? num : -num);
            }
            
            else{
                int last = st.top();
                st.pop();
                if(op == '*') last *= num;
                else last /= num;
                st.push(last);
            }
            ss >> op;
        }
        
        int sum = 0;
        while(!st.empty()){
            sum += st.top();
            st.pop();
        }
        return sum;
    }
};