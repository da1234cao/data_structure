#include <vector>
#include <cassert>
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
    int findRoot(vector<int>& inorder, int inorder_left, int inorder_right, int val){
        return find(inorder.begin()+inorder_left,inorder.begin()+inorder_right,val) - inorder.begin();
    }

    TreeNode* recursive_buildTree(vector<int>& preorder, int preorder_left, int preorder_right,vector<int>& inorder, int inorder_left, int inorder_right){
        // preorder[preorder_left,preorder_right] 的左闭右开区间，为先序遍历
        // inorder[inorder_left,inorder_right] 的左闭右开区间，为中序遍历
        
        // assert(preorder_right - preorder_left == inorder_right - inorder_left);
        if(inorder_left == inorder_right){
            return nullptr;
        }
        
        int rootVal = preorder[preorder_left];
        TreeNode* root = new TreeNode(rootVal); // 当前区间的根节点
        int root_in_inorder = findRoot(inorder,inorder_left,inorder_right,rootVal);

        // 切割中序
        pair<int,int> new_inorder_left_tree(inorder_left,root_in_inorder);
        pair<int,int> new_inorder_right_tree(root_in_inorder+1,inorder_right);
        // 切割先序
        pair<int,int> new_preorder_left_tree(preorder_left+1,preorder_left+1+(root_in_inorder-inorder_left));
        pair<int,int> new_preorder_right_tree(preorder_left+1+(root_in_inorder-inorder_left),preorder_right);

        root->left =  recursive_buildTree(preorder,new_preorder_left_tree.first,new_preorder_left_tree.second,inorder,new_inorder_left_tree.first,new_inorder_left_tree.second);
        root->right =  recursive_buildTree(preorder,new_preorder_right_tree.first,new_preorder_right_tree.second,inorder,new_inorder_right_tree.first,new_inorder_right_tree.second);
    
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return recursive_buildTree(preorder,0,preorder.size(),inorder,0,inorder.size());
    }
};