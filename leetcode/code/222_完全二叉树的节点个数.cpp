
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
    int countNodes(TreeNode* root) {
        // 如果当前树是完全二叉树。树节点个数：2^(h-1)-1
        // 如果当前树不是完全二叉树。树节点个数：1+左子树节点个数+右子树节点个数
        if(root == nullptr) 
            return 0;
        
        int leftDepth = 0; // 左子树高度
        int rightDepth = 0; // 右子树高度
        TreeNode* leftNode = root->left;
        TreeNode* rightNode = root->right;

        while(leftNode != nullptr){
            leftDepth++;
            leftNode = leftNode->left;
        }

        while(rightNode != nullptr){
            rightDepth++;
            rightNode = rightNode->right;
        }

        if(leftDepth == rightDepth){ //以root为根节点的树为满二叉树
            return (2<<(leftDepth+1-1))-1;
        }else{
            return 1 + countNodes(root->left) + countNodes(root->right);
        }

    }
};