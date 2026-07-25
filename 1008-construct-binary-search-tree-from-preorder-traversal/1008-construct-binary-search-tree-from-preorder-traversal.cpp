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
    TreeNode* insertnodes(TreeNode* root,int val){
        if(root == nullptr){
            return new TreeNode(val);
        }
        if(val > root->val){
            root->right = insertnodes(root->right,val);
        }
        if(val < root->val){
            root->left = insertnodes(root->left,val);
        }
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = nullptr;
        for(int i =0;i<preorder.size();i++){
            root = insertnodes(root,preorder[i]);
        }
        return root;
    }
};