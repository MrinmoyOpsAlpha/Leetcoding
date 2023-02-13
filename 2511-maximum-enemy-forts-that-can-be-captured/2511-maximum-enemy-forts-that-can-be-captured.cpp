class Solution {
public:
    int captureForts(vector<int>& forts) {
        int ans = 0;        
        int i=0,j=0;
        
        while(j<forts.size()){
            if(forts[j] != 0){
                if(forts[i] == - forts[j]){
                    ans = max(ans,j-i-1);
                }
                i=j;
            }
            j++;
        }
        
        return ans;
    }
};