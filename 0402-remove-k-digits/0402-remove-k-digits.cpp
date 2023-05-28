class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        int n = num.size();
        int count = k;
        
        for(int i=0;i<n;i++){
            while(!st.empty() && count > 0 && st.top() > num[i]){
                count--;
                st.pop();
            }
            st.push(num[i]);
        }
        
        while(st.size() != n-k) st.pop();
        
        string res = "";
        while(!st.empty())
        {
            res += st.top();
            st.pop();
        }
        reverse(res.begin() , res.end());

        while(res[0]=='0') res.erase(0,1);
        
        return (res=="") ? "0":res;
    }
};