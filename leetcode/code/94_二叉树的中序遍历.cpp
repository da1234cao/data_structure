#include <vector>
#include <iostream>
#include <climits>
#include <stack>

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
    // 二叉树的递归中序遍历
    void recursive_inorderTraversal(TreeNode* root, vector<int>& result){
        if(root == nullptr) return;
        recursive_inorderTraversal(root->left,result); // 左
        result.push_back(root->val); // 中
        recursive_inorderTraversal(root->right,result); // 右
    }

    // 二叉树的迭代中序遍历
    // // 错误，会重复迭代下方节点
    // void iteration_inorderTraversal(TreeNode* root, vector<int>& result){
    //     if(root == nullptr) return;
    //     stack<TreeNode*> st;
    //     st.push(root);
    //     TreeNode* node;

    //     while(!st.empty()){
    //         node = st.top();
    //         while(node->left != nullptr){ // 以初始node为根的树，一直迭代到其最左侧
    //             node = node->left;
    //             st.push(node);
    //         }

    //         // 输的最左节点有两种情况：叶子节点;没有左孩子&&有右孩子
    //         node = st.top();
    //         if(node->left == nullptr && node->right == nullptr){
    //             // 最左节点为叶子节点。
    //             // 叶子节点出栈，叶子节点的父节点若存在的话，也出栈。若叶子的父节点存在，且父节点存在右孩子，右孩子压栈
    //             result.push_back(node->val); // 左
    //             st.pop();
    //             if(!st.empty()){ // 叶子节点不为根
    //                 node = st.top();
    //                 result.push_back(node->val); // 中
    //                 st.pop();
    //                 if(node->right != nullptr) st.push(node->right); // 叶子节点的父节点的右孩子压栈
    //             }  
    //         }else if(node->left == nullptr && node->right != nullptr){
    //             // 最左节点为:没有左孩子&&有右孩子
    //             // 当前节点出栈，右孩子压栈
    //             result.push_back(node->val); // 中
    //             st.pop();
    //             st.push(node->right);
    //         }
    //     }
    // }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        recursive_inorderTraversal(root,result);
        return result;
    }
};