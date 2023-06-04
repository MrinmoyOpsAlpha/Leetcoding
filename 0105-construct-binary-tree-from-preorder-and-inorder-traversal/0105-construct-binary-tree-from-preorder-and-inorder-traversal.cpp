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
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int& index, int start, int end) {
        if (start > end) return nullptr;

        TreeNode* root = new TreeNode(preorder[index]);

        int splitIndex = start;
        while (inorder[splitIndex] != preorder[index]) {
            splitIndex++;
        }
        index++;

        root->left = build(preorder, inorder, index, start, splitIndex - 1);
        root->right = build(preorder, inorder, index, splitIndex + 1, end);
        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int index = 0;
        return build(preorder, inorder, index, 0, inorder.size() - 1);
    }
};
