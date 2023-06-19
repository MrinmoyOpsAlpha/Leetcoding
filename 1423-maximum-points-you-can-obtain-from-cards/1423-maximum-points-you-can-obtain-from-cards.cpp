class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int l = 0;
        int r = cardPoints.size() - k;
        int total = accumulate(cardPoints.begin() + r,cardPoints.end(),0);
        
        int res = total;
        
        while(r < cardPoints.size()){
            total += (cardPoints[l] - cardPoints[r]);
            res = max(res,total);
            l++;
            r++;
        }
        
        return res;
    }
};