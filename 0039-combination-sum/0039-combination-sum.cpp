class Solution {
public:
    
    void combination(vector<int>& candidates, int target,vector<vector<int>>& ans,int currSum,int currIndex,vector<int> currComb){
        
        if(currSum>target) return;
        
        if(currSum==target){
            ans.push_back(currComb);
            return;
        }
        
        for(int i=currIndex;i<candidates.size();i++){
            currSum = currSum + candidates[i];
            currComb.push_back(candidates[i]);
            combination(candidates,target,ans,currSum,i,currComb);
            currSum=currSum-candidates[i];
            currComb.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> currComb;
        combination(candidates,target,ans,0,0,currComb);
        return ans;
    }
};