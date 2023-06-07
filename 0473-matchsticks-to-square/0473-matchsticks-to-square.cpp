class Solution {
private:
    int a,b,c,d;
    bool dfs(vector<int>& matchsticks, int i){
        if(i == matchsticks.size()){
           if(a==0 && b==0 && c==0 && d==0) return true;
           else return false;
        }
        
        if(matchsticks[i] <= a){
            a = a - matchsticks[i];
            if(dfs(matchsticks,i+1)) return true; 
            a = a + matchsticks[i];
        }
        if(matchsticks[i] <= b){
            b = b - matchsticks[i];
            if(dfs(matchsticks,i+1)) return true; 
            b = b + matchsticks[i];
        }
        
        if(matchsticks[i] <= c){
            c = c - matchsticks[i];
            if(dfs(matchsticks,i+1)) return true; 
            c = c + matchsticks[i];
        }
        
        if(matchsticks[i] <= d){
            d = d - matchsticks[i];
            if(dfs(matchsticks,i+1)) return true; 
            d = d + matchsticks[i];
        }
        return false;
    }
public:
    bool makesquare(vector<int>& matchsticks) {
        if(matchsticks.size() < 4) return false;
        int sum = accumulate(matchsticks.begin(),matchsticks.end(),0);
        if(sum%4 != 0) return false;
        int sizeSum = sum / 4;
        a=sizeSum,b=sizeSum,c=sizeSum,d=sizeSum;
        sort(matchsticks.rbegin(), matchsticks.rend());
		return dfs(matchsticks,0);
    }
};