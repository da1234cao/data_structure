
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root->val < p->val && root->val < q->val)
            return lowestCommonAncestor(root->right,p,q); //两个节点比当前根节点大，到右子树中查找
        if(root->val > p->val && root->val > q->val)
            return lowestCommonAncestor(root->left,p,q); //两个节点比当前根节点小，到左子树中查找
        return root; // 如果一个大于根，一个小于根，根为公共祖先。如果p或q等于根节点，根为公共祖先
    }
};