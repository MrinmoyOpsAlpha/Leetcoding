class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        int n = asteroids.size();
        for(int i=0;i<n;i++){
            while(!st.empty() && asteroids[i] < 0 && st.top() > 0){
                int diff = asteroids[i] + st.top();
                if(diff < 0) st.pop();
                else if(diff > 0) asteroids[i] = 0;
                else asteroids[i]=0 , st.pop();
            }
            
            if(asteroids[i]) st.push(asteroids[i]);
        }
        
        vector<int> ans(st.size());
        for(int i = st.size()-1;i>=0;i--){
            ans[i] = st.top();
            st.pop();
        }
        return ans;
    }
};