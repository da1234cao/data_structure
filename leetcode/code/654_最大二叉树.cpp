#include <vector>
#include <cassert>

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
    int findMaxLoc(vector<int>& nums, int left, int right){
        //在nums[left,right]的左闭右开区间中，返回最大值下表
        // assert(right-left>0);
        int maxLoc = left;
        for(int i=left+1; i<right; i++){
            if(nums[i] > nums[maxLoc])
                maxLoc = i;
        }
        return maxLoc;
    }

    TreeNode* recursive_constructMaximumBinaryTree(vector<int>& nums, int left, int right){
        // 在nums[left,right]的左闭右开区间中，构建最大二叉树
        if(left >= right)
            return nullptr;
        
        int maxLoc = findMaxLoc(nums,left,right);
        TreeNode* root = new TreeNode(nums[maxLoc]); // 最大值为根
        root->left = recursive_constructMaximumBinaryTree(nums,left,maxLoc); // 递归建立左子树
        root->right = recursive_constructMaximumBinaryTree(nums,maxLoc+1,right); // 递归建立右子树

        return root;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return recursive_constructMaximumBinaryTree(nums,0,nums.size());
    }
};