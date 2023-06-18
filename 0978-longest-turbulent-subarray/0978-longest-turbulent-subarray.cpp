class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int l = 0, r = 1;
        int res = 1;
        string prev = "";
        
        while (r < arr.size()) {
            if (arr[r - 1] > arr[r] && prev != ">") {
                res = max(res, r - l + 1);
                r = r + 1;
                prev = ">";
            }
            else if (arr[r - 1] < arr[r] && prev != "<") {
                res = max(res, r - l + 1);
                r = r + 1;
                prev = "<";
            }
            else {
                r = (arr[r] == arr[r - 1]) ? r + 1 : r;
                l = r - 1;
                prev = "";
            }
        }
        
        return res;
    }
};
