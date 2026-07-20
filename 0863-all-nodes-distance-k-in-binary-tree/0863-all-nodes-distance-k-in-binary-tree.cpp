/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*,TreeNode*> parent;
    void createparent(TreeNode* root){
        if(root == nullptr) return;
        if(root->left != nullptr){
            parent[root->left] = root;
        }
        createparent(root->left);

        if(root->right != nullptr){
            parent[root->right] = root;
        }
        createparent(root->right);

    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k){
        createparent(root);

        unordered_set<int>visited;
        queue<TreeNode*>que;
        vector<int>ans;

       
        que.push(target);
        visited.insert(target->val);
        int level = 0;
        while(!que.empty()){

            int size = que.size();
             if(level == k){
                    break;
                }

            for(int i = 0;i<size;i++){
               TreeNode* node = que.front();
               que.pop();

               if(node->left != nullptr && !visited.count(node->left->val)){
                que.push(node->left);
                visited.insert(node->left->val);
               }
               
               if(node->right != nullptr && !visited.count(node->right->val)){
                que.push(node->right);
                visited.insert(node->right->val);
               }
                if(parent.count(node) && !visited.count(parent[node]->val)){
                que.push(parent[node]);
                visited.insert(parent[node]->val);
               }

            } level++;
        }
        while(!que.empty()){
            ans.push_back(que.front()->val);
            que.pop();
        }

       return ans;
    }
};