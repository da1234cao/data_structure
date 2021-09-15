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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root == nullptr) return result;

        queue<TreeNode*> levelNodeAddress;
        levelNodeAddress.push(root);
        while(!levelNodeAddress.empty()){
            int levelNodeNum = levelNodeAddress.size();
            vector<int> levelNodeVal;
            for(int i=0; i<levelNodeNum; i++){ // 处理当前层节点
                TreeNode* node = levelNodeAddress.front();
                levelNodeAddress.pop();
                levelNodeVal.push_back(node->val);
                if(node->left != nullptr)
                    levelNodeAddress.push(node->left);
                if(node->right != nullptr)
                    levelNodeAddress.push(node->right);
            }
            result.push_back(levelNodeVal);
        }

        return result;
    }
};