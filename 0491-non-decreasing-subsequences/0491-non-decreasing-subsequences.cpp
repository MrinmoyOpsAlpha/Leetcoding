class Solution {
public:
    void dfs(vector<int> &nums,set<vector<int>> &ans,vector<int> &temp,int start,int size){
        if(size>=2){
            ans.insert(temp);
        }
        
        for(int i=start;i<nums.size();i++){
            if(temp.size()==0 || nums[i] >= temp[temp.size()-1]){
                temp.push_back(nums[i]);
                dfs(nums,ans,temp,i+1,size+1);
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> ans;
        vector<int> temp;
        dfs(nums,ans,temp,0,0);
        
        vector<vector<int>> res(ans.begin(),ans.end());
        return res;
    }
};