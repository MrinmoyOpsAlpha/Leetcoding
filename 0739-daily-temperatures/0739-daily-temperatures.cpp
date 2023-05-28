class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> answer;
        stack<pair<int,int>> st;
        int n = temperatures.size();
        
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && temperatures[i] >= st.top().first){
                st.pop();
            }
            
            if(st.empty()){
                answer.push_back(0);
            }
            else{
                answer.push_back(st.top().second-i);
            }
            
            st.push({temperatures[i],i});
        }
        
        reverse(answer.begin(),answer.end());
        return answer;
    }
};