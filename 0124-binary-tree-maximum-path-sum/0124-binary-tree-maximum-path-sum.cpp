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
    int maxSum = INT_MIN;
    int Solve(TreeNode* root){
        if(root == nullptr) return 0;

        int l = Solve(root->left);
        int r = Solve(root->right);

        int niche_hi_mil_gaya_ans = l + r + root->val;

        int koi_ek_acha_he = max(l,r) + root->val;

        int only_root_acha = root->val;

        maxSum = max({maxSum ,niche_hi_mil_gaya_ans, koi_ek_acha_he, only_root_acha});

        return max(koi_ek_acha_he, only_root_acha);
    }
    int maxPathSum(TreeNode* root) {
        Solve(root);
        return maxSum;
    }
};