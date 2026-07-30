class Info {
public:
    int minNode, maxNode, sum;

    Info(int minNode, int maxNode, int sum) {
        this->minNode = minNode;
        this->maxNode = maxNode;
        this->sum = sum;
    }
};

class Solution {
public:
    int ans = 0;

    Info helper(TreeNode* root) {

        if (root == nullptr)
            return Info(INT_MAX, INT_MIN, 0);

        auto left = helper(root->left);
        auto right = helper(root->right);

        if (left.maxNode < root->val &&
            root->val < right.minNode) {

            int currSum = left.sum + right.sum + root->val;

            ans = max(ans, currSum);

            return Info(
                min(root->val, left.minNode),
                max(root->val, right.maxNode),
                currSum
            );
        }

        return Info(INT_MIN, INT_MAX, 0);
    }

    int maxSumBST(TreeNode* root) {
        helper(root);
        return ans;
    }
};