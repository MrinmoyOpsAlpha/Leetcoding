class Solution {
private:
    bool backtrack(int index,int k,int currSum, int target,vector<bool>&vis,vector<int>& nums){
        if(k==1) return true;
        if(index >= nums.size()) return false;
        if(currSum == target) return backtrack(0,k-1,0,target,vis,nums);
        
        for(int i = index; i<nums.size();i++){
            if(vis[i] || currSum + nums[i] > target) continue;
            vis[i] = true;
            if(backtrack(i+1,k,currSum + nums[i],target,vis,nums)) return true;
            vis[i] =false;
        }
        return false;
    }
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum =accumulate(nums.begin(),nums.end(),0);
        vector<bool>vis(nums.size(),false);
        if(sum%k!=0)
            return false;
        int target=sum/k;
        sort(begin(nums),end(nums),greater<int>());
        return backtrack(0,k,0,target,vis,nums);
    }
};