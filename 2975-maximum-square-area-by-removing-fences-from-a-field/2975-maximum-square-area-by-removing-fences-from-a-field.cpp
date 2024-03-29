class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);
        
        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());
        
        unordered_set<int> st;
        long long ans = 0;
        long long int MOD = 1e9 + 7;
        
        for(int i=0;i<hFences.size();i++){
            for(int j =0;j<hFences.size();j++){
                st.insert(abs(hFences[i]-hFences[j]));
            }
        }
        
        for(int i=0;i<vFences.size();i++){
            for(int j=0;j<vFences.size();j++){
                if(i!=j && st.find(abs(vFences[i] - vFences[j])) != st.end()){
                    ans = max(ans , (long long)abs(vFences[i] - vFences[j]));
                }
            }
        }
        
        return (ans == 0) ? -1 : (ans * ans) % MOD;
    }
};