class Solution {
public:
    unordered_map<TreeNode*,TreeNode*> parent;
    TreeNode* startNode = nullptr;    // ADD KIYA

    void createparent(TreeNode* root, int start){   // start parameter ADD KIYA
        if(root == nullptr) return;

        if(root->val == start)        // ADD KIYA
            startNode = root;

        if(root->left){
            parent[root->left] = root;
        }
        createparent(root->left, start);

        if(root->right){
            parent[root->right] = root;
        }
        createparent(root->right, start);
    }

    int amountOfTime(TreeNode* root, int start) {

        queue<TreeNode*> que;

        unordered_set<TreeNode*> visited;   // CHANGE KIYA

        createparent(root, start);          // CHANGE KIYA

        que.push(startNode);                // CHANGE KIYA
        visited.insert(startNode);          // CHANGE KIYA

        int level = -1;                     // CHANGE KIYA

        while(!que.empty()){

            int size = que.size();

            for(int i=0;i<size;i++){

                TreeNode* temp = que.front();
                que.pop();

                if(temp->left != nullptr && !visited.count(temp->left)){   // CHANGE KIYA
                    que.push(temp->left);
                    visited.insert(temp->left);
                }

                if(temp->right != nullptr && !visited.count(temp->right)){  // CHANGE KIYA
                    que.push(temp->right);
                    visited.insert(temp->right);
                }

                if(parent.count(temp) && !visited.count(parent[temp])){     // CHANGE KIYA
                    que.push(parent[temp]);
                    visited.insert(parent[temp]);
                }
            }

            level++;
        }

        return level;
    }
};