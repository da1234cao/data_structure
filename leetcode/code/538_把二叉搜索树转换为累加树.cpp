
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    TreeNode* pre = nullptr;
    void recurisive_convertBST(TreeNode* root){
        // 按照右中左，递归遍历二叉树，并计算包含自己节点的前缀和
        if(root == nullptr)
            return;
        recurisive_convertBST(root->right);
        if(pre != nullptr){
            root->val = root->val + pre->val;
        }
        pre = root;
        recurisive_convertBST(root->left);
    }

public:
    TreeNode* convertBST(TreeNode* root) {
        recurisive_convertBST(root);
        return root;
    }
};