class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = prices[0];
        int maxProf = 0;
        
        for(int i=1;i<prices.size();i++){
            int sell = prices[i] - buy;
            maxProf = max(maxProf,sell);
            buy = min(buy,prices[i]);
        }
        
        return maxProf;
    }
};