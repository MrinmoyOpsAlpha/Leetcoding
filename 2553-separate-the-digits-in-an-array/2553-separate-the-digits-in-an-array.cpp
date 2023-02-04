class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        int n = nums.size();
        string s="";
        for(int i=0;i<n;i++){
            string c = to_string(nums[i]);
            s = s + c;
        }
        
        vector<int> ans;
        for(int i=0;i<s.size();i++){
            ans.push_back(s[i] - '0');
        }
        
        return ans;
    }
};