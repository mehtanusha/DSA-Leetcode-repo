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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>>ans;
        if(root == nullptr){
            return ans;
        }

        queue<TreeNode*>que;
        que.push(root);
        while(!que.empty()){
            int size = que.size();
            vector<int>res;
            for(int i=0;i<size;i++){
                TreeNode* temp = que.front();
                res.push_back(temp->val);
                que.pop();

                if(temp->left){
                    que.push(temp->left);
                }
                if(temp->right){
                    que.push(temp->right);
                }
            }
            ans.push_back(res);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};