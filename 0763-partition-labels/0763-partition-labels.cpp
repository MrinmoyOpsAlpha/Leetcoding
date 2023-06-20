class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        vector<int> lastIndex(26);
        
        for(int i=0;i<n;i++){
            lastIndex[s[i] - 'a'] = i;
        }
        
        int size = 0;
        int end = 0;
        vector<int> result;
        
        for(int i=0;i<n;i++){
            size++;
            end = max(end, lastIndex[s[i] - 'a']);
            
            if(i == end){
                result.push_back(size);
                size = 0;
            }
        }
        
        return result;
    }
};