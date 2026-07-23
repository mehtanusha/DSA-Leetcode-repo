/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == nullptr) return "#";

        queue<TreeNode*>que;
        que.push(root);

        string ans = "";
        while(!que.empty()){
            TreeNode* node = que.front();
            que.pop();

            if(node == nullptr) ans = ans + "#" + ",";
            else{
                ans = ans + to_string(node->val) + ",";
                que.push(node->left);
                que.push(node->right);
            }
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "#") return nullptr;

       string temp = "";
       vector<string>vec;

       for(char ch : data){
        if(ch == ','){
            vec.push_back(temp);
            temp = "";
        }else{
            temp += ch;
        }
       }
       TreeNode * root = new TreeNode(stoi(vec[0]));
       queue<TreeNode*>que;
       que.push(root);
       int i =1;
       while(!que.empty() && i <vec.size()){
        TreeNode* curr = que.front();
        que.pop();

        if(vec[i] != "#"){
            curr->left = new TreeNode (stoi(vec[i]));
            que.push(curr->left);
        }
        i++;

        
        if(vec[i] != "#"){
            curr->right = new TreeNode (stoi(vec[i]));
            que.push(curr->right);
        }
        i++;
       }
       return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));