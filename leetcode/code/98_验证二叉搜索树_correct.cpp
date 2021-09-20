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
    void inorder_traverse(TreeNode* root, vector<int>& result){
        // 线索二叉树的中序遍历结果，为升序
        if(root == nullptr)
            return;
        inorder_traverse(root->left,result);
        result.push_back(root->val);
        inorder_traverse(root->right,result);
    }

    bool isValidBST(TreeNode* root) {
        vector<int> result;
        inorder_traverse(root,result);
        bool flag = true;
        for(int i=1; i<=result.size()-1; i++){
            if(result[i-1] >= result[i]){
                flag = false;
                break;
            }
        }
        return flag;
    }
};
