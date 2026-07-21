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
    TreeNode* solve(int start,int end,int& idx,vector<int>& inorder, vector<int>& postorder){
        if(start > end){
            return nullptr;
        }

        int rootval = postorder[idx];
        int i = start;
        while(i<=end){
            if(inorder[i] == rootval){
                break;
            }
            i++;
        }

        idx--;
        TreeNode* root = new TreeNode(rootval);
        root->right = solve(i+1,end,idx,inorder,postorder);
        root->left = solve(start,i-1,idx,inorder,postorder);
        return root;
        
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        int n = postorder.size();

        int idx = n-1;
        return solve(0,n-1,idx,inorder,postorder);
    }
};