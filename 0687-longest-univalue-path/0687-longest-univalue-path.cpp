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
    int helper(TreeNode* root,int &longestPath){
        if(!root) return 0;
        
        int leftPath = (root->left) ? helper(root->left,longestPath) : 0;
        int rightPath = (root->right) ? helper(root->right,longestPath) : 0;
        
        leftPath = (root->left && root->val == root->left->val)? leftPath + 1 : 0;
        rightPath = (root->right && root->val == root->right->val)? rightPath + 1 : 0;
        
        longestPath = max(longestPath,leftPath + rightPath);
        return max(leftPath,rightPath);
    }
public:
    int longestUnivaluePath(TreeNode* root) {
        int longestPath = 0;
        helper(root,longestPath);
        return longestPath;
    }
};