#include <vector>
#include <string>
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<vector<int>> result_int;
        vector<string> result_string;
        
        if(root == nullptr)
            return result_string;
        
        queue<TreeNode*> que_node;
        queue<vector<int>> que_path;
        que_node.push(root);
        que_path.push({root->val});

        while(!que_node.empty()){
            int size = que_node.size();
            for(int i=0; i<size; i++){ 
                TreeNode* node = que_node.front();
                que_node.pop();
                vector<int> path = que_path.front();
                que_path.pop();
                if(node->left != nullptr){
                    que_node.push(node->left);
                    vector<int> new_path = path;
                    new_path.push_back(node->left->val);
                    que_path.push(new_path);
                }
                if(node->right != nullptr){
                    que_node.push(node->right);
                    vector<int> new_path = path;
                    new_path.push_back(node->right->val);
                    que_path.push(new_path);
                }
                if(node->left == nullptr && node->right == nullptr)
                    result_int.push_back(path);
            }
        }

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