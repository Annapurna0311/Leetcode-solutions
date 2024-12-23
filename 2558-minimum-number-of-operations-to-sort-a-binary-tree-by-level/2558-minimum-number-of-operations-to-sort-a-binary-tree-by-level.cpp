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
    int getMinSwaps(vector<int>& res){
        int swaps = 0;
        vector<int> target = res;
        sort(target.begin(), target.end());

        unordered_map<int,int> pos;
        for(int i=0;i<res.size();i++){
            pos[res[i]] = i;
        }
        for(int i=0;i<res.size();i++){
            if(res[i] != target[i]){
                swaps++;
                int curr = pos[target[i]];
                pos[res[i]] = curr;
                swap(res[curr] , res[i]);
            }
        }
        return swaps;
    }
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        int totalSwaps = 0;
        q.push(root);
        while(!q.empty()){
            int s = q.size();
            vector<int> res(s);
            for(int i=0;i<s;i++){
                TreeNode* x = q.front();
                q.pop();
                if(x->left != NULL) q.push(x->left);
                if(x->right != NULL) q.push(x->right);
                res[i] = x->val;
            }
            totalSwaps += getMinSwaps(res);
        }
        return totalSwaps;

    }
};