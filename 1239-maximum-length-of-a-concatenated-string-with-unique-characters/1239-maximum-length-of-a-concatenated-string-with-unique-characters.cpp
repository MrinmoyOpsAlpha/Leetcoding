class Solution {
private:
    int maxLengthHelper(vector<string>& arr, string s, int index){
        unordered_set<char> st(s.begin(),s.end());
        
        if(s.size() != st.size()) return 0;
        
        int size = s.size();
        for(int i = index;i<arr.size();i++){
            size = max(size, maxLengthHelper(arr, s + arr[i], i + 1));
        }
        return size;
    }
public:
    int maxLength(vector<string>& arr) {
        return maxLengthHelper(arr,"",0);
    }
};