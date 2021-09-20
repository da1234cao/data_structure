
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 反例：[5,4,6,null,null,3,7]
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(root == nullptr)
            return true;
        if(root->left != nullptr && root->val <= root->left->val)
            return false;
        if(root->right != nullptr && root->val >= root->right->val)
            return false;
        
        return isValidBST(root->left) && isValidBST(root->right);
    }
};