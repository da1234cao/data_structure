
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
    int treeHigh(TreeNode* root){
        if(root == nullptr)
            return 0;
        int leftHigh = treeHigh(root->left);
        int rightHigh = treeHigh(root->right);
        return leftHigh > rightHigh ? leftHigh+1 : rightHigh+1;
    }

    bool isBalanced(TreeNode* root) {
        if(root == nullptr)
            return true;
        
        int leftHigh = treeHigh(root->left);
        int rightHigh = treeHigh(root->right);
        if(leftHigh - rightHigh < -1 || leftHigh - rightHigh > 1)
            return false;
        else
            return isBalanced(root->left) && isBalanced(root->right);
    }
};