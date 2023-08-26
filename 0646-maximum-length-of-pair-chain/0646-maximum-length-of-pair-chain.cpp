class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),[](vector<int>&v1,vector<int>&v2){
            return v1[1] < v2[1];
        });

        int cnt = 1;
        auto temp = pairs[0];
        
        for(int i=1;i<pairs.size();i++){
            if(temp[1] < pairs[i][0]){
                cnt++;
                temp = pairs[i];
            }
        }
        
        return cnt;
    }
};