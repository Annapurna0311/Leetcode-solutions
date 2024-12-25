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
    vector<int> largestValues(TreeNode* root) {
       if(!root) return {};
       vector<int> res;
       queue<TreeNode*> q;
       q.push(root);
       while(!q.empty()){
           int curr_level = q.size();
           int max_val = INT_MIN;
           for(int i=0;i<curr_level;i++){
               TreeNode* node = q.front();
               q.pop();
               max_val = max(max_val,node->val);
               if(node->left) q.push(node->left);
               if(node->right) q.push(node->right);
           }
           res.push_back(max_val);
       }
       return res;
    }
};
