
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // 如果找到一个节点，发现左子树出现结点p，右子树出现节点q，或者 左子树出现结点q，右子树出现节点p，那么该节点就是节点p和q的最近公共祖先。
        // 从下向上遍历，需要将下面遍历的结果传递到上面。
        // 有两种类型的传递。第一种是，不断迭代自己->父亲->祖父->...的节点，层层向上,这是常规的递归过程。第二种是，利用第一种，传递遇到某个节点，将该节点保送传递到上面。
        // 本题，两个节点，必然一个先遇到，一个后遇到。保送先遇到的节点。当遇到两个节点时候，当前树的根节点为公共祖先节点，将祖先节点保送到上面。
        if(root == p || root == q || root == nullptr)
            return root;
        
        TreeNode* left = lowestCommonAncestor(root->left,p,q);
        TreeNode* right = lowestCommonAncestor(root->right,p,q);

        if(left != nullptr && right != nullptr)
            return root; // 从下向上遍历，以root为根的树，左右都遇见，将root保送上去
        
        if(left != nullptr && right == nullptr)
            return left; // 如果先遇到到的节点在left，将left保送上去
        if(left == nullptr && right != nullptr)
            return right; // 如果先遇到节点在right，将right保送上去
        else
            return nullptr;
    }
};