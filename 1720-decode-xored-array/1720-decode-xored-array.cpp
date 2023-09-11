class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> res;
        
        res.push_back(first);
        
        for(auto it:encoded){
            int temp = it ^ first;
            res.push_back(temp);
            first = temp;
        }
        
        return res;
    }
};