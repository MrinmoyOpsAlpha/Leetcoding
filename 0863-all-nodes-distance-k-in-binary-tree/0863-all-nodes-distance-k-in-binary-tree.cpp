/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    void buildGraph(TreeNode* root,unordered_map<int,vector<int>> &graph){
        if(root->left){
            graph[root->val].push_back(root->left->val);
            graph[root->left->val].push_back(root->val);
            buildGraph(root->left,graph);
        }
        
        if(root->right){
            graph[root->val].push_back(root->right->val);
            graph[root->right->val].push_back(root->val);
            buildGraph(root->right,graph);
        }
    }
    
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(k==0)
            return {target->val};
        
        unordered_map<int,vector<int>> graph;
        unordered_map<int,bool> visited;
        vector<int> res;
        
        buildGraph(root,graph);
        
        queue<int> q;        
        int level = 0;        
        q.push(target->val);
        
        while(!q.empty()){
            int size = q.size();
            
            for(int i=0;i<size;i++){
                auto node = q.front();
                q.pop();
                
                visited[node] = true;
                for(auto it:graph[node]){
                    if(!visited[it]){
                        q.push(it);
                    }
                }
            }
            
            level++;
            
            if(level == k){
                while(!q.empty()){
                    res.push_back(q.front());
                    q.pop();
                }
                break;
            }
        }
        
        return res;        
    }
};