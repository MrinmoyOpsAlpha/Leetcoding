class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> ans;
        int carry = k;
        
        for(int i=num.size()-1; i>=0 || carry>0; i--){
            if(i>=0) carry += num[i];
            ans.push_back(carry%10);
            carry /= 10;
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
