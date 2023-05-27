class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for(auto it:tokens){
            if(it.size() > 1 || isdigit(it[0])){
                st.push(stoi(it));
            }

            else{
                int num2 = st.top(); st.pop();
                int num1 = st.top(); st.pop();

                int result = 0;
                if(it == "+") result = num1 + num2;
                else if(it == "-") result = num1 - num2;
                else if(it == "*") result = num1 * num2;
                else if(it == "/") result = num1 / num2; // Perform floating-point division

                st.push(result);
            }
        }

        return st.top();
    }
};
