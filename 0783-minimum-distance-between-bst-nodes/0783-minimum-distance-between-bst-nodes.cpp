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
    int minDiffInBST(TreeNode* root) {
        vector<int> BST;
        stack<TreeNode*> st;
        
        TreeNode* temp = root;
        
        while(!st.empty() || temp != NULL){
            if(temp!=NULL){
                st.push(temp);
                temp = temp->left;
            }
            else{
                temp = st.top();
                st.pop();
                BST.push_back(temp->val);
                temp = temp->right;
            }
        }
        int ans = INT_MAX;
        for(int i=0;i<BST.size()-1;i++){
            ans = min(BST[i+1] -BST[i],ans);
        }
        return ans;
    }
};