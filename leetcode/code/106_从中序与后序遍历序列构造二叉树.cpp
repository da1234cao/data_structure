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

    TreeNode* recursive_buildTree(vector<int>& inorder, int inorder_left, int inorder_right, vector<int>& postorder, int postorder_left, int postorder_right){
        // inorder[inorder_left,inorder_right] 的左闭右开区间，为中序遍历
        // postorder[postorder_left,postorder_right] 的左闭右开区间，为后序遍历

        // assert(postorder_right - postorder_left == inorder_right - inorder_left);
        if(inorder_left == inorder_right){
            return nullptr;
        }
        
        int rootVal = postorder[postorder_right-1];
        TreeNode* root = new TreeNode(rootVal); // 当前区间的根节点
        int root_in_inorder = findRoot(inorder,inorder_left,inorder_right,rootVal);

        // 切割中序
        pair<int,int> new_inorder_left_tree(inorder_left,root_in_inorder);
        pair<int,int> new_inorder_right_tree(root_in_inorder+1,inorder_right);
        // 切割后序
        pair<int,int> new_postorder_left_tree(postorder_left,postorder_left+(root_in_inorder-inorder_left));
        pair<int,int> new_postorder_right_tree(postorder_left+(root_in_inorder-inorder_left),postorder_right-1);

        root->left =  recursive_buildTree(inorder,new_inorder_left_tree.first,new_inorder_left_tree.second,postorder,new_postorder_left_tree.first,new_postorder_left_tree.second);
        root->right =  recursive_buildTree(inorder,new_inorder_right_tree.first,new_inorder_right_tree.second,postorder,new_postorder_right_tree.first,new_postorder_right_tree.second);
    
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return recursive_buildTree(inorder,0,inorder.size(),postorder,0,postorder.size());
    }
};