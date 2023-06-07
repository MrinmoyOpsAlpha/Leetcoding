typedef unsigned long long ll;
class Solution {
private:
    bool check(string& s, ll prev, int index, int cnt){
        if(s.size() == index) return cnt > 1;
        
        ll num = 0;
        bool flag = false;
        
        for(int i = index ; i<s.size();i++){
            num = num * 10;
            num = num + s[i]-'0';
            if(prev == -1 || prev - 1 == num){
                flag = flag || check(s,num,i+1,cnt+1);
            }
            else if(prev != -1 && num >= prev) break;
        }
        return flag;
    }
public:
    bool splitString(string s) {
        return check(s,-1,0,0);
    }
};