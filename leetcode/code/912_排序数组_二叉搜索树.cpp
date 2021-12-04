// 详见：https://blog.csdn.net/sinat_38816924/article/details/120392445
#include <vector>
#include <iostream>

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
    vector<int> sortArray(vector<int>& nums) {
        Tree tree(nums);
        vector<int> result;
        tree.inorderTraverse(tree.getRoot(),result);
        return result;
    }
};


int main(void){
    // 去重并排序
    vector<int> nums = {5,1,1,2,0,0};
    Solution sol;
    vector<int> ans = sol.sortArray(nums);
    for(int num : ans)
        cout<<num<<" ";
}