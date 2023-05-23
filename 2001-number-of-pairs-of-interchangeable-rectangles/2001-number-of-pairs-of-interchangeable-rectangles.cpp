class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        int n = rectangles.size();
        unordered_map<double,double> mp;
        long long result = 0;
        
        for(int i = 0;i<n;i++){
            double ratio = (double)rectangles[i][0] /(double)rectangles[i][1];
            if(mp.find(ratio) != mp.end()) {
                result = result + mp[ratio];
            }
            mp[ratio]++;
        }
        return result;
    }
};