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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*>st1;
        vector<int>ans;
        if(root == nullptr) return ans;

        st1.push(root);       
        while(!st1.empty()){
          root = st1.top();
          st1.pop();
          ans.push_back(root->val);

          if(root->left != nullptr) st1.push(root->left);
          if(root->right != nullptr) st1.push(root->right);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};