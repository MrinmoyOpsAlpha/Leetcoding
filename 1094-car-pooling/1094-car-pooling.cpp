class Solution {
private:
    static bool comp(vector<int> a, vector<int> b){
        if( a[1]<b[1] || (a[1]==b[1]) && (a[2]<b[2])) return true;
        return false;
    }
public:
    bool carPooling(vector<vector<int>>& trips, int capacity){
        int n = trips.size();
        sort(trips.begin(),trips.end(),comp);
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq; // destination,passengers
        int passengers = 0;
        
        for(int i = 0;i<n;i++){
            
            while(!pq.empty() && pq.top().first <= trips[i][1]){
                passengers = passengers - pq.top().second;
                pq.pop();
            }
            
            pq.push({trips[i][2], trips[i][0]});
            passengers = passengers + trips[i][0];
            
            if(passengers > capacity) return false;
        }
        
        return true;
    }
};