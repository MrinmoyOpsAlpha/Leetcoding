class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        int sum = 0,value1=0,value2=0;
        for(int i=0;i<operations.size();i++){
            if(operations[i]=="C") st.pop();
            else if(operations[i]=="D") st.push(st.top()*2);
            else if(operations[i]=="+") {
                value1 = st.top();
                st.pop();
                value2 = st.top();
                st.push(value1);
                st.push(value1 + value2);
            }
            else st.push(stoi(operations[i]));
        }
    
        while(!st.empty()){
            sum = sum +st.top();
            st.pop();
        }
        return sum;
    }
};