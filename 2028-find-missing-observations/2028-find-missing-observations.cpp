class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int total = (m+n) * mean - accumulate(rolls.begin(),rolls.end(),0);
        
        if(total > 6*n || total < n) return {};
        
        vector<int> res;
        while(n){
            int dice = min(total - n + 1 , 6);
            res.push_back(dice);
            total -= dice;
            n--;
        }
        
        return res;
    }
};