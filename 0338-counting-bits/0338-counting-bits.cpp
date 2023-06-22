class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        
        for(int i=0;i<=n;i++){
            int k = i;
            int cnt = 0;
            while(k){
                cnt += k % 2;
                k = k >> 1;
            }
            ans[i] = cnt;
        }
        return ans;
    }
};