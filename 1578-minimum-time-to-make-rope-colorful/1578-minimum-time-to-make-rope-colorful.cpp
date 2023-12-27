class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        stack<pair<char,int>> st;
        
        int res = 0, n = colors.size();
        
        for(int i=0;i<n;i++){
            if(!st.empty() && st.top().first == colors[i]){
                if(st.top().second < neededTime[i]){
                    res += st.top().second;
                    st.pop();
                    st.push({colors[i], neededTime[i]});
                }
                else{
                    res += neededTime[i];
                }
            }
            
            else    
                st.push({colors[i],neededTime[i]});
        }
        
        return res;
    }
};