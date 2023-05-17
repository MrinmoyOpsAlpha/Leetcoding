class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        int maxNo = -1;    
        
        for(int i = n-1;i>=0;i--){
            int  temp = max(maxNo,arr[i]);
            arr[i] = maxNo;
            maxNo = temp;
        }
        return arr;
    }
};