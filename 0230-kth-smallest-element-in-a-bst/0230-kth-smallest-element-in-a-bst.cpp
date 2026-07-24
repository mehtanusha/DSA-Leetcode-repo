class Solution {
public:
    int ans;

    void inorder(TreeNode* root, int k, int &cnt) {
        if(root == nullptr){
            return;
        }

        inorder(root->left, k, cnt);

        cnt++;
        if(cnt == k){
            ans = root->val;
            return;
        }

        inorder(root->right, k, cnt);
    }

    int kthSmallest(TreeNode* root, int k) {
        if(root == nullptr) return -1;

        int cnt = 0;
        inorder(root, k, cnt);

        return ans;
    }
};