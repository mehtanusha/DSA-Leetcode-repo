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

class Info {
    public : 
    int leftmax,rightmin,sum;

    Info(int leftmax,int rightmin,int sum){
        this->leftmax = leftmax;
        this->rightmin = rightmin;
        this->sum = sum;
    }
};
class Solution {
public:
    int ans = 0;

    Info helper(TreeNode* root){
        if(root == nullptr) return  Info(INT_MIN,INT_MAX,0);

        auto left = helper(root->left);
        auto right = helper(root->right);

        if(left.leftmax < root->val && root->val < right.rightmin){
            int currsum = left.sum + right.sum + root->val;

            ans = max(ans,currsum);

            return Info(max(root->val,right.leftmax),min(root->val,left.rightmin),currsum);
        }
        else{
            return Info(INT_MAX,INT_MIN,0);
        }
    }

    int maxSumBST(TreeNode* root) {
       helper(root);
       return ans; 
    }
};