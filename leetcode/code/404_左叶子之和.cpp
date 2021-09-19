
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
    void recursive_sumOfLeftLeaves(TreeNode* root, int& leftSum){
        if(root == nullptr) // 习惯使用此作为递归出口
            return; 
        
        if(root->left != nullptr && root->left->left == nullptr && root->left->right == nullptr)
            leftSum += root->left->val; // 为父节点的左孩子，且该左孩子为叶子节点
        
        recursive_sumOfLeftLeaves(root->left,leftSum);
        recursive_sumOfLeftLeaves(root->right,leftSum);
    }

    int sumOfLeftLeaves(TreeNode* root) {
        int leftSum = 0;
        recursive_sumOfLeftLeaves(root,leftSum);
        return leftSum;
    }
};