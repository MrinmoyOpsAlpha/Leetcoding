class Solution {
private:
    int solve(vector<string>& arr, string res, int index){
        unordered_set<char> st(res.begin(),res.end());
        
        if(st.size() != res.size()) return 0;
        
        int size = res.size();
        for(int i = index;i<arr.size() ; i++){
            size = max(size, solve(arr,res + arr[i],i+1));
        }
        
        return size;
    }
public:
    int maxLength(vector<string>& arr) {
        
        return solve(arr,"",0);
    }
};