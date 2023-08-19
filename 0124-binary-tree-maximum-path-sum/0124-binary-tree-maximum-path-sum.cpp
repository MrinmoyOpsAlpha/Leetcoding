/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int helper(TreeNode* root,int &maxi){
        if(!root) return 0;
        
        int leftSum = max(helper(root->left,maxi),0);
        int rightSum = max(helper(root->right,maxi),0);
        maxi = max(maxi,root->val + leftSum + rightSum);
        return root->val + max(leftSum,rightSum);
    }
public:
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        helper(root,maxi);
        return maxi;
    }
};