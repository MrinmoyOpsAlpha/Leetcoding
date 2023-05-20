class Solution {
public:
    int maxNumberOfBalloons(string text) {
        map<char, int> mp;
        
        for (char ch : text) {
            if (ch == 'b' || ch == 'a' || ch == 'l' || ch == 'o' || ch == 'n') {
                mp[ch]++;
            }
        }
        
        int minCnt = min({mp['b'], mp['a'], mp['n'], mp['l'] / 2, mp['o'] / 2});
        
        return minCnt;
    }
};
