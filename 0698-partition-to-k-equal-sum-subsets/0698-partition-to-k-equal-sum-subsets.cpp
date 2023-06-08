class Solution {
// private:
//     bool backtrack(int index, int k, int currSum, int target, vector<int>& nums, vector<bool>& used) {
//         if (k == 1) {
//             return true;
//         }
//         if (currSum == target) {
//             return backtrack(0, k - 1, 0, target, nums, used);
//         }
//         if(index>=nums.size()) return false;
//         for (int i = index; i < nums.size(); i++) {
//             if (used[i] || currSum + nums[i] > target) {
//                 continue;
//             }

//             used[i] = true;
//             if (backtrack(i + 1, k, currSum + nums[i], target, nums, used)) {
//                 return true;
//             }
//             used[i] = false;
//         }

//         return false;
//     }

public:
bool canPartitionKSubsets(vector<int>& nums, int k) {
    
      int sum =accumulate(nums.begin(),nums.end(),0);
      vector<bool>vis(nums.size(),false);
      if(sum%k!=0)
        return false;
      int s=sum/k;
      sort(begin(nums),end(nums),greater<int>());// For avoid extra calculation
      return is_possible(nums,0,s,k,0,vis);
  }
 bool is_possible(vector<int>&nums,int curr,int sum,int k,int start,vector<bool>&vis)
{
        if(k==1)
            return true;
        if(start>=nums.size()) //This line is important to avoid tle
           return false;
        if(curr==sum)
                return is_possible(nums,0,sum,k-1,0,vis);
    
    for(int i=start;i<nums.size();i++)
    {
        if(vis[i] || nums[i]+curr>sum)
            continue;
        vis[i]=true;
        if(is_possible(nums,curr+nums[i],sum,k,i+1,vis))
            return true;
        vis[i]=false;
    }
    return false;
}
};
