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
    TreeNode* recursive_sortedArrayToBST(vector<int>& nums, int left, int right){
        // nums[left,right]的有序闭区间，建立一个平和二叉搜索树
        // 自行确保left<=right,并且nums[left],nums[right]存在
        int mid = left + (right-left)/2;
        TreeNode* root = new TreeNode(nums[mid]);                                // if (left > right) return nullptr;
        if(left < mid) root->left = recursive_sortedArrayToBST(nums,left,mid-1); // if(left >= mid) return null;
        if(right > mid) root->right = recursive_sortedArrayToBST(nums,mid+1,right); // if(right <= mid) return null;
        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.empty())
            return nullptr;
        return recursive_sortedArrayToBST(nums,0,nums.size()-1);
    }
};