class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProf=0,minProf=prices[0];
        
        for(int i=1;i<prices.size();i++){
            if(prices[i]>prices[i-1]){
                maxProf=max(maxProf,prices[i]-minProf);
            }
            else{
                minProf=min(minProf,prices[i]);
            }
        }
        return maxProf;
    }
};