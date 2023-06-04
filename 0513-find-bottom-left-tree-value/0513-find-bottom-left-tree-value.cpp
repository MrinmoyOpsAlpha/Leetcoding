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
    
    void dfs(TreeNode* root,int level,vector<int> &v){
        if(!root) return;
        if(v.size()==level) v.push_back(root->val);
        if(root->left) dfs(root->left,level+1,v);
        if(root->right) dfs(root->right,level+1,v);
    }
public:
    int findBottomLeftValue(TreeNode* root) {
         vector<int> v;
        dfs(root,0, v);
        return v.back();
    }
};