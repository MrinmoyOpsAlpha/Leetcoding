class Solution {
    void middleCheck(string s,int i,int j, int& counter){
        while(i>=0 && j<=s.size() && s[i] == s[j]){
            counter++;
            i--;
            j++;
        }
    }
public:
    int countSubstrings(string s) {
        int counter = 0;
        for(int i=0;i<s.size();i++){
            middleCheck(s,i,i,counter);
            middleCheck(s,i,i+1,counter);
        }
        return counter;
    }
};