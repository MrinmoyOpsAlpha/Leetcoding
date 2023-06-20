class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        set<int> st;
        
        for(auto t : triplets){
            if(t[0] > target[0] || t[1] > target[1] || t[2] > target[2])
                continue;
            
            for(int j=0;j<3;j++){
                if(t[j] == target[j])
                    st.insert(j);
            }
        }
        
        return st.size() == 3;
    }
};