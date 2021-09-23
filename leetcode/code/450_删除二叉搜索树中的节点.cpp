
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr)
            return nullptr;
        if(key < root->val)
            root->left = deleteNode(root->left,key);
        else if(key > root->val)
            root->right = deleteNode(root->right,key);
        else{
            if(root->left == nullptr && root->right == nullptr){ // 删除节点为叶子节点，直接删除
                delete root;
                root = nullptr;
            }else if(root->right != nullptr){ // 删除节点，存在右子树，用后继节点替代
                TreeNode* successor = root->right;
                while(successor->left != nullptr)
                    successor = successor->left;
                root->val = successor->val;
                root->right = deleteNode(root->right,successor->val);
            }else{ // 删除节点，仅存在左子树，用前驱节点代替
                TreeNode* predecessor = root->left;
                while(predecessor->right != nullptr)
                    predecessor = predecessor->right;
                root->val = predecessor->val;
                root->left = deleteNode(root->left,predecessor->val);
            }
        }
        return root;
    }
};