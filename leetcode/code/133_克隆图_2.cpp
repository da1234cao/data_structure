#include <vector>
#include <unordered_map>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution {
public:
    unordered_map<Node*,Node*> visited; // 存储新图和旧图之间的映射<old,new>

    Node* cloneGraph(Node* node) {
        if(node == nullptr)
            return node;
        
        if(visited.find(node) != visited.end()) //如果旧图中的该节点已经访问，返回其对应的新节点
            return visited[node];
        
        visited[node] = new Node(node->val);

        for(auto neighbor : node->neighbors){ // 深度遍历节点
            visited[node]->neighbors.push_back(cloneGraph(neighbor));
        }

        return visited[node]; // 层层返回
    }
};