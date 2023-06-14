class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        map<int, int> sums;
        for (int num : nums) {
            sums[num] += num;
        }
        
        int take = 0, skip = 0;
        
        for (auto& p : sums){
            if(sums.find(p.first - 1) == sums.end()){
                skip = take;
                take += p.second;
            }
            else{
                int temp = max(skip + p.second, take);
                skip = take;
                take = temp;
            }
        }
        
        return take;
    }
};