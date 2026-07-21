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
    TreeNode* solve(int start,int end,int& idx,vector<int>& preorder, vector<int>& inorder){
        if(start > end){
            return nullptr;
        }

       int rootval = preorder[idx];
        int i = start;
        for(; i<=end ; i++){
            if(inorder[i] == rootval){
                break;
            }
        }
        idx++;

        TreeNode* root = new TreeNode(rootval);
        root->left = solve(start,i-1,idx,preorder,inorder);
        root->right = solve(i+1,end,idx,preorder,inorder);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n  = preorder.size();

        int idx = 0;

        return solve(0,n-1,idx,preorder,inorder);
    }
};