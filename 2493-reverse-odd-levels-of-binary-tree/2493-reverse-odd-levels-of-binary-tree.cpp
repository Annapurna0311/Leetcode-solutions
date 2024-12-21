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
    TreeNode* reverseOddLevels(TreeNode* root) {
        // level order traversal and then at odd position switch
        if(root == NULL) return NULL;
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while(!q.empty()){
            int s = q.size();
            vector<TreeNode*> res;
            for(int i=0;i<s;i++){
                TreeNode* x = q.front();
                q.pop();
                res.push_back(x);
                if(x->left !=NULL) q.push(x->left);
                if(x->right != NULL) q.push(x->right);
            }
            if(level%2 == 1){
                int l = 0 , r = res.size() - 1;
                while(l < r){
                    int temp = res[l]->val;
                    res[l]->val = res[r]->val;
                    res[r]->val = temp;
                    l++;
                    r--;
                }
            }
            level++;
        }
          
        return root;
        
    }
};