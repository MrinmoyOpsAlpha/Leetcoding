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
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* temp = root;
        vector<int> v;
        
        while(!st.empty() || temp){
            if(temp){
                st.push(temp);
                temp = temp->left;
            }
            else{
                temp = st.top();
                st.pop();
                v.push_back(temp->val);
                temp = temp->right;
            }
        }
        
        return v;
    }
};