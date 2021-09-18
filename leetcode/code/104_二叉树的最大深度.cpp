#include <queue>

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
    int maxDepth(TreeNode* root) {
        if(root == nullptr) 
            return 0;
        // 当前树的高度 = 1+max(左子树的高度,右子树的高度)
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);
        return leftDepth > rightDepth ? leftDepth+1:rightDepth+1;
    }
};

// class Solution {
// public:
//     int maxDepth(TreeNode* root) {
//         if(root == nullptr) 
//             return 0;

//         queue<TreeNode*> que;
//         que.push(root);
//         int depth = 0;
//         while(!que.empty()){
//             depth++;
//             int size = que.size();
//             for(int i=0; i<size; i++){
//                 TreeNode* node = que.front();
//                 que.pop();
//                 if(node->left != nullptr) que.push(node->left);
//                 if(node->right != nullptr) que.push(node->right);
//             }
//         }

//         return depth;
//     }
// };