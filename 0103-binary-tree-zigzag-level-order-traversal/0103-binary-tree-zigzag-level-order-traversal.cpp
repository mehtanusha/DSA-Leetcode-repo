class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        vector<vector<int>> ans;
        queue<TreeNode*> que;

        if (root == nullptr)
            return ans;

        int number = 0;
        que.push(root);

        while (!que.empty()) {

            int size = que.size();
            vector<int> level;

            for (int i = 0; i < size; i++) {

                TreeNode* node = que.front();
                que.pop();

                level.push_back(node->val);

                // Hamesha Left -> Right hi push karna hai
                if (node->left != nullptr)
                    que.push(node->left);

                if (node->right != nullptr)
                    que.push(node->right);
            }

            // Odd level par reverse kar do
            if (number % 2 == 1) {
                reverse(level.begin(), level.end());
            }

            ans.push_back(level);
            number++;
        }

        return ans;
    }
};