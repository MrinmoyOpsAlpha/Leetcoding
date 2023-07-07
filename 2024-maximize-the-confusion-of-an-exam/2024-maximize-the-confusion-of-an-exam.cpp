class Solution {
private:
    int count(string s, int k, char ch){
        int i = 0, j = 0, res = 0, cnt = 0;
        
        while(j<s.size()){
            cnt = cnt + (s[j] == ch);
            while(cnt > k){
                cnt = cnt - (s[i] == ch);
                i++;
            }
            res = max(res,j-i+1);
            j++;
        }
        
        return res;
    }        
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        return max(count(answerKey, k, 'T'),count(answerKey, k, 'F'));
    }
};