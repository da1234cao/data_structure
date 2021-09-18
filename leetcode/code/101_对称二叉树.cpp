#include <vector>
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
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr)
            return true;
        
        queue<TreeNode*> que;
        que.push(root->left);
        que.push(root->right);
        while(!que.empty()){
            TreeNode* leftNode = que.front(); que.pop(); // 待比较的左侧节点
            TreeNode* rightNode = que.front(); que.pop(); // 待比较的右侧节点
                                                          // 虽然这两个节点的父节点不相同
            if(leftNode == nullptr && rightNode == nullptr)
                continue;
            
            if((leftNode == nullptr && rightNode != nullptr) || (leftNode != nullptr && rightNode == nullptr) || (leftNode->val != rightNode->val) )
                return false;
            
            que.push(leftNode->left); // 放入左侧节点的左孩子
            que.push(rightNode->right); // 放入右侧节点的右孩子
            que.push(leftNode->right); // 放入左侧节点的右孩子
            que.push(rightNode->left); // 放入右侧节点的左孩子
        }

        return true;
    }
};