#include <vector>

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
    void recursive_postorderTraversal(TreeNode* root, vector<int>& result){
        if(root == nullptr) return;
        recursive_postorderTraversal(root->left,result);
        recursive_postorderTraversal(root->right,result);
        result.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        recursive_postorderTraversal(root,result);
        return result;
    }
};