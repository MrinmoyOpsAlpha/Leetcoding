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
    TreeNode* lca(TreeNode* root,int p,int q){
        if(!root || root->val == p || root->val == q) return root;
        
        TreeNode* left = lca(root->left,p,q);
        TreeNode* right = lca(root->right,p,q);
        
        if(!left) return right;
        if(!right) return left;
        return root;
    }
    
    bool getPath(TreeNode* root,int value, string &path){
        if(!root) return false;
        if(root->val == value) return true;
        
        bool findL = getPath(root->left,value,path += 'L');
        if(findL) return true;
        path.pop_back();
        

        bool findR = getPath(root->right,value,path += 'R');
        if(findR) return true;
        path.pop_back();
        
        return false;
    }
    
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        
        TreeNode* point = lca(root,startValue,destValue);
        
        string p1,p2;
        getPath(point,startValue,p1);
        getPath(point,destValue,p2);
        
        for(auto &c:p1) c = 'U';
        
        return p1 + p2;
    }
};