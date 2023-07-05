class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int left = 0, right = cardPoints.size() - k;
        int total = accumulate(cardPoints.begin() + right, cardPoints.end(),0);
        
        int res = total;
        
        while(right < cardPoints.size()){
            total += (cardPoints[left] - cardPoints[right]);
            res = max(res,total);
            left++;
            right++;
        }
        
        return res;
    }
};
