#include <vector>
#include <queue>
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
    Node* cloneGraph(Node* node) {
        if(node == nullptr)
            return node;

        // 广度优先遍历
        // 这道题目用set应该也可以避免重复。但是map更好，它直接存储两张图的映射<old,nes>
        // 遍历旧图时候，在map中建立新图
        unordered_map<Node*, Node*> visited;
        queue<Node*> Q;

        visited[node] = new Node(node->val);
        Q.push(node);
        while(!Q.empty()){
            Node* n = Q.front();
            Q.pop();
            for(auto neighbor : n->neighbors){
                if(visited.find(neighbor) == visited.end()){
                    visited[neighbor] = new Node(neighbor->val); // 克隆一个新节点
                    visited[n]->neighbors.push_back(visited[neighbor]); // 添加指向
                    Q.push(neighbor);  // 邻居节点添加到队列中
                }else{
                    visited[n]->neighbors.push_back(visited[neighbor]); // 该节点已经遇见并创建过，这里只要添加一个指向即可
                }
            }
        }

        return visited[node];
    }
};
