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
    int height(TreeNode* root){
        if(root == nullptr) return 0;
        if(root->left == nullptr && root->right == nullptr) return 1;

        int L = root->left != nullptr ? height(root->left) : INT_MIN;
        int R = root->right != nullptr ? height(root->right) : INT_MIN;

        return 1 + max(L,R);
    }
    bool isBalanced(TreeNode* root) {
        if(root == nullptr) return true;

        int left = height(root->left);
        int right = height(root->right);
        if(abs(right - left) > 1 ) return false;

        return isBalanced(root->left) && isBalanced(root->right);

    }
};