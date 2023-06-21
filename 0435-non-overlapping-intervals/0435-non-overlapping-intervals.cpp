class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.size() <= 1) {
            return 0;
        }
        
        sort(intervals.begin(), intervals.end());
        
        vector<int> tempInterval = intervals[0];        
        int count = 0;
        
        for (int i = 1; i < intervals.size(); i++) {
            if (tempInterval[1] > intervals[i][0]) {
                count++;
                tempInterval[1] = min(tempInterval[1], intervals[i][1]);
            } else {
                tempInterval = intervals[i];
            }
        }
        
        return count;
    }
};
