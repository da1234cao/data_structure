
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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == nullptr){
            root = new TreeNode(val);
            return root;
        }

        TreeNode* node = root;
        while(1){
            if(val == node->val){
                break;
            }else if(val < node->val && node->left == nullptr){
                node->left = new TreeNode(val);
                break;
            }else if(val < node->val && node->left != nullptr){
                node = node->left;
            }else if(val > node->val && node->right == nullptr){
                node->right = new TreeNode(val);
                break;
            }else if(val > node->val && node->right != nullptr){
                node = node->right;
            }
        }

        return root;
    }
};