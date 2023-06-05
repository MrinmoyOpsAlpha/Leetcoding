class Solution {
public:
    string reorganizeString(string s) {
        string res = "";
        unordered_map<char,int> mp;
        priority_queue<pair<int,char>>pq;
        
        for(auto it:s) mp[it]++;
        
        for(auto it:mp) pq.push({it.second,it.first});
        
        while(pq.size() > 1){
            auto top1 = pq.top(); pq.pop();
            auto top2 = pq.top(); pq.pop();
            
            res = res + top1.second;
            res = res + top2.second;
            
            top1.first -= 1;
            top2.first -= 1;
            
            if(top1.first) pq.push(top1);
            if(top2.first) pq.push(top2);
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