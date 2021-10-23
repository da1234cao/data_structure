#include <algorithm>

using namespace std;

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
    int rob(TreeNode* root) {
        if(root == nullptr)
            return 0;
        
        int steal_root = root->val;
        if(root->left) 
            steal_root = steal_root + rob(root->left->left) + rob(root->left->right);
        if(root->right)
            steal_root = steal_root + rob(root->right->left) + rob(root->right->right);
        
        int not_steal_root = rob(root->left) + rob(root->right);

        return max(steal_root,not_steal_root);
    }
};