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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == nullptr && q == nullptr) return true;
        if((p == nullptr && q != nullptr ) || ((q == nullptr && p != nullptr ))) return false;

        queue<TreeNode*>que;
        que.push(p);
        que.push(q);
        while(!que.empty()){
            TreeNode* temp1 = que.front();
            que.pop();
            TreeNode* temp2 = que.front();
            que.pop();

            if(temp1->val != temp2->val) return false;
            if((temp1->left != nullptr && temp2 ->left == nullptr) || (temp1->right != nullptr && temp2 ->right == nullptr) ||(temp1->left == nullptr && temp2 ->left != nullptr) || (temp1->right == nullptr && temp2 ->right != nullptr) ) return false;


            if(temp1->left != nullptr && temp2 ->left != nullptr){
                que.push(temp1->left);
                que.push(temp2->left);
            }
            if(temp1->right != nullptr && temp2 ->right != nullptr){
                que.push(temp1->right);
                que.push(temp2->right);
            }
        }
        return true;
    }
};