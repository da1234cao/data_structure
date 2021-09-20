#include <vector>
#include <climits>

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
private:
    TreeNode* pre;
    int count,max_appr = INT_MIN;
    vector<int> result;
    void inorder_traverse(TreeNode* root){
        if(root == nullptr)
            return;
        
        inorder_traverse(root->left);
        if(pre != nullptr){
            if(root->val == pre->val) // 使用了上一层节节点pre。本层还没给它进行赋值操作
                count++;
            else
                count = 1;
            if(count > max_appr){
                result.clear();
                result.push_back(root->val);
                max_appr = count;
            }else if(count == max_appr){
                result.push_back(root->val);
            }
        }else{ // 最左节点没有pre，预放入
            count = 1;
            result.push_back(root->val);
            max_appr = 1;
        }
        pre = root; // 保存前一个节点。这个遍历在上一层进行了赋值。
        inorder_traverse(root->right);
    }

public:
    vector<int> findMode(TreeNode* root) {
        inorder_traverse(root);
        return result;
    }
};