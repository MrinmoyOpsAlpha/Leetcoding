class Solution {
private:
    bool solve(string &res, int index, unordered_set<string> &st){
        if(index >= res.size()) return !st.count(res);
        
        res[index] = '0';
        if(solve(res,index+1,st)) {
            return true;
        }
        
        res[index] = '1';
        if(solve(res,index+1,st)){
            return true;
        }
        
        return false;
    }
public:
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<string> st(nums.begin(),nums.end());
        int n = nums[0].size();
        string res(n, ' ');
        solve(res,0,st);
        return res;
    }
};