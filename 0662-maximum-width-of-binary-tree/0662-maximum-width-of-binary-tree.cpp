class Solution {
public:
    typedef unsigned long long l1;
    int widthOfBinaryTree(TreeNode* root) {
        
        if(root == nullptr) return 0;

        queue<pair<TreeNode*, l1>> que;

        que.push({root,0});
        l1 maxwidth = 0;

        while(!que.empty()){
           
           int size = que.size();

           l1 left = que.front().second;
           l1 right = que.back().second;

           maxwidth = max(maxwidth, right - left + 1);

           for(int i = 0; i < size; i++){

                TreeNode* temp = que.front().first;
                l1 index = que.front().second;

                que.pop();

                if(temp->left != nullptr){
                    que.push({temp->left, (long long)2*index + 1});
                }

                if(temp->right != nullptr){
                    que.push({temp->right, (long long)2*index + 2});
                }
           }
        }

        return maxwidth;
    }
};