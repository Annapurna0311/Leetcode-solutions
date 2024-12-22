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
    vector<double> averageOfLevels(TreeNode* root) {
        // do a level order traversal 
        vector<double> ans;
        queue<TreeNode*> q;
        if(root == nullptr) return ans;
        q.push(root);
        while(!q.empty()){
            long temp = 0;
            int s = q.size();
            for(int i=0;i<s;i++){
                TreeNode* it = q.front();
                q.pop();
                if(it->left != NULL) q.push(it->left);
                if(it->right != NULL) q.push(it->right);
                temp += it->val;
            }
            ans.push_back((double) temp / s);
        }
        return ans;
    }
};