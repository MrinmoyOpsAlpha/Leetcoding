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
    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int& index, int start, int end){
        if(start>end) return NULL;
        
        TreeNode* root = new TreeNode(postorder[index]);
        
        int splitIndex = start;
        while(splitIndex <= end && postorder[index] != inorder[splitIndex]){
            splitIndex++;
        }
        index--;
        
        root->right = build(inorder, postorder, index, splitIndex + 1, end);
        root->left = build(inorder, postorder, index, start, splitIndex - 1);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int index = inorder.size()-1;
        return build(inorder,postorder,index,0,inorder.size()-1);
    }
};