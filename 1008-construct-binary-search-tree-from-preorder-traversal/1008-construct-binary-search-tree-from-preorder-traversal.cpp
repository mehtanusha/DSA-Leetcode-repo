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
    TreeNode* create(vector<int>& preorder,int &i,int bound){
       if(i == preorder.size() || preorder[i] > bound){
        return nullptr;
       }

       TreeNode* root = new TreeNode (preorder[i++]);

       root->left = create(preorder,i,root->val);
       root->right = create(preorder,i,bound);
       return root;
        
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
       int i = 0;
       return create(preorder,i,INT_MAX);
    }
};