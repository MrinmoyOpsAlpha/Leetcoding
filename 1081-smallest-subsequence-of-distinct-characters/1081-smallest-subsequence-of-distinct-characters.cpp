class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> seen(26,0), freq(26,0);
        stack<char> st;
        
        for(int i=0;i<s.size();i++){
            freq[s[i] - 'a']++;
        }
        
        for(int i=0;i<s.size();i++){
            
            freq[s[i] - 'a']--;
            
            if(seen[s[i] - 'a']) continue;
            
            while(!st.empty() && st.top() > s[i] && freq[st.top() - 'a'] != 0){
                seen[st.top() - 'a'] = 0;
                st.pop();
            }
            
            st.push(s[i]);
            seen[s[i] - 'a'] = 1;
        }
        
        string ans ="";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};