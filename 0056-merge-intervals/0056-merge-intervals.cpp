class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        
        if (intervals.empty()) {
            return res;
        }
        
        sort(intervals.begin(),intervals.end());        
        
        vector<int> tempInterval = intervals[0];
        
        for(int i=1;i<intervals.size();i++){
            if(tempInterval[0] <= intervals[i][1] && tempInterval[1] >= intervals[i][0]){
                tempInterval[0] = min(tempInterval[0] , intervals[i][0]);
                tempInterval[1] = max(tempInterval[1] , intervals[i][1]);
            }
            else{
                res.push_back(tempInterval);
                tempInterval = intervals[i];
            }
        }
        
        res.push_back(tempInterval);
        return res;
    }
};