class Solution {
public:
    string reorganizeString(string s) {
        map<char,int> mp;
        priority_queue<pair<int,char>> pq;
        string res = "";
        
        for(auto it:s) mp[it]++;
        for(auto it:mp) pq.push({it.second, it.first});
        
        while(pq.size() >= 2){
            auto top1 = pq.top(); pq.pop();
            auto top2 = pq.top(); pq.pop();
            
            res = res + top1.second;
            res = res + top2.second;
            
            if(top1.first - 1){
                top1.first = top1.first - 1;
                pq.push({top1.first, top1.second});
            }
            
            if(top2.first - 1){
                top2.first = top2.first - 1;
                pq.push({top2.first, top2.second});
            }
        }
        
        if(!pq.empty()) {
            if(pq.top().first > 1) return "";
            else{
                res += pq.top().second;
            }
        }
        
        return res;
    }
};