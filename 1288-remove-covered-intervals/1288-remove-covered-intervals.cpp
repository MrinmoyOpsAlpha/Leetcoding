class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        if (intervals.size() <= 1)
            return intervals.size();
        
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
        });
        
        vector<vector<int>> res;
        vector<int> tempInterval = intervals[0];
        
        for (int i = 1; i < intervals.size(); i++) {
            if (tempInterval[0] <= intervals[i][0] && tempInterval[1] >= intervals[i][1]) {
                tempInterval[1] = max(tempInterval[1], intervals[i][1]);
            } else {
                res.push_back(tempInterval);
                tempInterval = intervals[i];
            }
        }
        
        res.push_back(tempInterval);
        return res.size();
    }
};
