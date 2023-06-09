class Solution {
private:
    vector<string> turn(string s, int j){
        vector<string> res(2,s);
        res[0][j] = '0' + (res[0][j] - '0' + 1) % 10;
        res[1][j] = '0' + (res[1][j] - '0' - 1 + 10 ) % 10;
        return res;
    }
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead(begin(deadends), end(deadends)), seen({"0000"});
        if(dead.find("0000") != end(dead)) return -1; 
        if(target == "0000") return 0; 
        
        queue<string> q({"0000"});
        int minTurns = 0;
        
        while(!q.empty()){
            int n = q.size(); 
            minTurns++;
            
            for(int i=0;i<n;i++){
                auto curr_str = q.front() ;
                q.pop();
                for(int j = 0;j<4;j++){
                    for(auto adj_str : turn(curr_str,j)){
                        if(seen.find(adj_str) == end(seen) && dead.find(adj_str) == end(dead)){
                            if(target == adj_str) return minTurns;
                            else q.push(adj_str), seen.insert(adj_str);
                        }
                    }
                }
            }
        }
        return -1;
    }
};