#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>

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

class Solution {
public:
    enum dirt{left,right,end};

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<pair<dirt,dirt>> path_dirt; // 记录路径的方向，pair中存储<当前已走方向,待走方向>
        vector<int> path_int; // 记录路径的节点值
        vector<vector<int>> result_int;
        vector<string> result_string;

        if(root == nullptr)
            return result_string;

        // 得到第一条路径，当存在左孩子的时候，尽量向左孩子方向走
        TreeNode* node = root;
        path_int.push_back(node->val);
        while(node != nullptr){
            if(node ->left != nullptr && node->right != nullptr){
                node = node->left;
                path_dirt.push_back({left,right});
                path_int.push_back(node->val);
            }else if(node ->left != nullptr && node->right == nullptr){
                node = node->left;
                path_dirt.push_back({left,end});
                path_int.push_back(node->val);
            }else if(node ->left == nullptr && node->right != nullptr){
                node = node->right;
                path_dirt.push_back({right,end});
                path_int.push_back(node->val);
            }else{
                node = nullptr;
            }
        }
        result_int.push_back(path_int);

        // 当路径的最后一位是left，下一步为right。向right方向行走。
        // 当路径的最后一位的下一步是end，说明下一步无路可走，将其弹出
        // 直到最后路径为空
        while(!path_dirt.empty()){
            // 弹出路径尾部下一步为end的路径
            while( !path_dirt.empty() && path_dirt.back().second == end)
                path_dirt.pop_back();
            if(path_dirt.empty())
                break;
            
            // 路径的最后一条改为,向右走
            path_dirt[path_dirt.size()-1] = make_pair(right,end);
            TreeNode* node = root;
            path_int.clear();
            path_int.push_back(node->val);
            // 先走完path_dirt中既定的路线
            for(int i=0; i<path_dirt.size(); i++){ 
                if(path_dirt[i].first==left){
                    node = node->left;
                    path_int.push_back(node->val);
                }else if(path_dirt[i].first == right){
                    node = node->right;
                    path_int.push_back(node->val);
                }
            }
            // 若后续路线存在，接着往下走
            while(node != nullptr){
                if(node ->left != nullptr && node->right != nullptr){
                    node = node->left;
                    path_dirt.push_back({left,right});
                    path_int.push_back(node->val);
                }else if(node ->left != nullptr && node->right == nullptr){
                    node = node->left;
                    path_dirt.push_back({left,end});
                    path_int.push_back(node->val);
                }else if(node ->left == nullptr && node->right != nullptr){
                    node = node->right;
                    path_dirt.push_back({right,end});
                    path_int.push_back(node->val);
                }else{
                    node = nullptr;
                }
            }          
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