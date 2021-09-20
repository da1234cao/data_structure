#include <iostream>
#include <vector>

using namespace std;


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};


class Tree {
private:
    TreeNode* root=nullptr;
public:
    Tree(vector<int>& nums){
        buildTree(nums);
    }

    void insertNode(int val){
        if(root == nullptr){
            root = new TreeNode(val);
            return;
        }

        TreeNode* node = root;
        while(1){
            if(val == node->val)
                break;
            else if(val < node->val && node->left == nullptr){
                node->left = new TreeNode(val);
                break;
            }else if(val < node->val && node->left != nullptr){
                node = node->left;
            }else if(val > node->val && node->right == nullptr){
                node->right = new TreeNode(val);
                break;
            }else if(val > node->val && node->right != nullptr){
                node = node->right;
            }
        }
    }

    void buildTree(vector<int>& nums){
        for(auto num : nums)
            insertNode(num);
    }

    void inorderTraverse(TreeNode* root,vector<int>& result){
        if(root == nullptr)
            return;
        inorderTraverse(root->left,result);
        result.push_back(root->val);
        inorderTraverse(root->right,result);
    }

    TreeNode* getRoot(void){
        return root;
    }
};


class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == nullptr)
            return nullptr;
        if(val == root->val)
            return root;
        if(val < root->val)
            return searchBST(root->left,val);
        // if(val > root->val)
        //     return searchBST(root->right,val);
        return searchBST(root->right,val);
    }
};

int main(void){
    vector<int> nums = {4,2,7,1,3};
    Tree tree(nums);
    Solution s;
    TreeNode* result = s.searchBST(tree.getRoot(),nums[1]);
    if(result == nullptr)
        cout<<"error:cant find..."<<endl;
    else
        cout<<"find "<<nums[1]<<endl;
    return 0;
}