#include <queue>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iostream>

#define null INT32_MIN  // 使用INT32_MIN代替null

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution{
public:
    void recordParentAndLeaves(TreeNode* root, unordered_map<TreeNode*,TreeNode*>& child2parent, unordered_set<TreeNode*>& leaves){
        // 层次遍历二叉树，记录每个节点的父节点
        // 遇到叶子节点的时候，记录叶子节点
        if(root == nullptr)
            return;

        queue<TreeNode*> que;
        que.push(root);

        while(!que.empty()){
            int size = que.size();
            for(int i=0; i<size; i++){
                TreeNode* node = que.front();
                que.pop();
                if(node->left != nullptr){
                    que.push(node->left);
                    child2parent.emplace(make_pair(node->left,node));
                }
                if(node->right != nullptr){
                    que.push(node->right);
                    child2parent.emplace(make_pair(node->right,node));
                }
                if(node->left == nullptr && node->right == nullptr)
                    leaves.insert(node);
            }
        }
    }

    vector<string> binaryTreePaths(TreeNode* root){
        unordered_map<TreeNode*,TreeNode*> child2parent;
        unordered_set<TreeNode*> leaves;
        recordParentAndLeaves(root,child2parent,leaves);

        vector<vector<int>> result_int;
        vector<string> result_string;
        vector<int> path_int;
        
        // 从叶子节点，溯源到根节点
        for(auto leaf : leaves){
            path_int.clear();
            path_int.push_back(leaf->val);
            TreeNode* node = leaf;
            while(child2parent.count(node)){
                node = child2parent[node];
                path_int.push_back(node->val);
            }
            reverse(path_int.begin(),path_int.end());
            result_int.push_back(path_int);
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


class Tree{
private:
    TreeNode* root = nullptr;

public:
    TreeNode* getRoot(){
        return root;
    }

    // 层次建立二叉树
    void buildTree(vector<int>& nums){
        const int len = nums.size();
        if(len == 0)
            return;
        
        root = new TreeNode(nums[0]);
        queue<pair<int,TreeNode*>> que; // 存储当前层节点信息：<数组中的下表，对于节点的地址>
        que.push(make_pair(0,root));

        while(!que.empty()){ // 层次遍历
            int que_size = que.size(); // 当前层节点个数
            for(int i=0; i<que_size; i++){
                pair<int,TreeNode*> nodePair = que.front();
                que.pop();
                int leftLoc = nodePair.first*2+1;
                int rightLoc = nodePair.first*2+2;
                if(leftLoc < len && nums[leftLoc] != null){ // 左节点存在
                    TreeNode* node = new TreeNode(nums[leftLoc]);
                    nodePair.second->left = node;
                    que.push(make_pair(leftLoc,node));
                }
                if(rightLoc < len && nums[rightLoc] != null){ // 右节点存在
                    TreeNode* node = new TreeNode(nums[rightLoc]);
                    nodePair.second->right = node;
                    que.push(make_pair(rightLoc,node));
                }
            }
        }
    }

    // 销毁二叉树
    void destroyTree(TreeNode* root){
        if(root!=nullptr){
            destroyTree(root->left);
            destroyTree(root->right);
            delete root;
        }
    }

};


int main(void){
    // 构建二叉树
    vector<int> nums = {1,2,3,null,5}; 
    Tree tree;
    tree.buildTree(nums);

    // 查找二叉树的所有路径
    Solution s;
    vector<string> result = s.binaryTreePaths(tree.getRoot());
    for(auto num : result)
        cout<<num<<endl;
    
    // 销毁二叉树
    tree.destroyTree(tree.getRoot());
}