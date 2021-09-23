
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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        // 三个递归出口
        if(root == nullptr)
            return nullptr;
        if(root->val < low)
            return trimBST(root->right,low,high); // 中间小于low，整个左子树和根丢弃
        if(root->val > high)
            return trimBST(root->left,low,high); // 中间大于high，整个右子树和根丢弃
        
        // 根节点得以保存

        root->left = trimBST(root->left,low,high);
        root->right = trimBST(root->right,low,high);
        return root;
    }
};