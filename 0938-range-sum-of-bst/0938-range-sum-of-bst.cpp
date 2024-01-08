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
private:
    int sum = 0;
    void helper(TreeNode* root, int low, int high){
        
        if(!root) return ;
        
        if(root->left){
            helper(root->left,low,high);
        }
        
        if(root->right){
            helper(root->right,low,high);
        }
        
        if(root->val >= low && root->val <= high){
            sum = sum + root->val;
        }
        
    }
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        helper(root,low,high);
        return sum;
    }
};