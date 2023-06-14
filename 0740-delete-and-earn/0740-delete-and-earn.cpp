class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        map<int, int> sums;
        for (int num : nums) {
            sums[num] += num;
        }
        
        int rob1 = 0 , rob2 = 0;
        
        for(auto it:sums){
            if(sums.find(it.first - 1) == sums.end()){
                rob1 = rob2;
                rob2 += it.second;
            }
            
            else{
                int temp = max(it.second + rob1, rob2);
                rob1 = rob2;
                rob2 = temp;
            }
        }
        
        return rob2;
    }
};