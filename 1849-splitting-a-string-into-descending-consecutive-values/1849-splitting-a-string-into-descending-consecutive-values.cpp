typedef unsigned long long ll;
class Solution {
private:
    bool solve(string &s, ll last, int index, int count){
        if(index >= s.size()) return count>1;
        ll num = 0 ;
        bool flag = false;
        
        for(int i=index;i<s.size();i++){
            num = num * 10;
            num = num + (s[i] - '0');
            
            if(last == -1 || last == num + 1){
                flag = flag || solve(s, num , i + 1, count + 1);
            }
            else if(last != -1 &&  num >= last) break;
        }
        return flag;
    }
public:
    bool splitString(string s) {
        return solve(s,-1,0,0);
    }
};