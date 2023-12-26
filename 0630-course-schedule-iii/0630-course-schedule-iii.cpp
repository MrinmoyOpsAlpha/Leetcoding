class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        if(courses.size() <= 0) return 0;
        sort(courses.begin(),courses.end(), [](const vector<int>& a, vector<int>& b){
            return a[1] < b[1];
        });
        
        int sum = 0;
        priority_queue<int> pq;
        for(auto it: courses){
            sum = sum + it[0];
            pq.push(it[0]);
            if(sum > it[1]){
                sum = sum - pq.top();
                pq.pop();
            }
        }
        
        return pq.size();
    }
};