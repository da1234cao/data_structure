#include <vector>
#include <string>

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
    void constructPAHT(TreeNode* root, vector<int> path, vector<vector<int>>& result_int){
        if(root == nullptr) // 遇到叶子是终止条件没错。这里习惯还是将遍历结束作为终止条件
            return;
        path.push_back(root->val); // 当前path副本，添加一个节点
        if(root->left == nullptr && root->right == nullptr) // 遇到叶子节点，即找到一条路径
            result_int.push_back(path);
        constructPAHT(root->left,path,result_int);
        constructPAHT(root->right,path,result_int);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<vector<int>> result_int;
        vector<string> result_string;
        constructPAHT(root,{},result_int);

        // 将int的路径，转换成string的路径
        for(vector<int> path_int : result_int){
            string path_string;
            for(int val : path_int){
                path_string += to_string(val);
                path_string += "->";
            }
            path_string.pop_back();
            path_string.pop_back();
            result_string.push_back(path_string);
        }

        return result_string;
    }
};