#include <queue>
#include <unordered_set>
#include <iostream>

using namespace std;

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int node_size = isConnected.size();
        if(node_size == 0)
            return 0;

        int ret = 0; // 记录图的连通分量
        unordered_set<int> appear; // 记录已经出现的节点
        queue<pair<int,int>> Q; // 用于层次遍历图

        ret++;
        appear.insert(0);
        Q.push({0,0});

again:
        while(!Q.empty()){
            pair<int,int> node = Q.front();
            Q.pop();
            int row = node.first;
            int col = node.second;
            for(int i=0; i<node_size; i++){
                if(isConnected[col][i] == 1 && appear.find(i)==appear.end()){
                    Q.push(make_pair(col,i));
                    appear.insert(i);
                }
            }
        }

        if(appear.size() < node_size){ // 没有遍历完
            for(int i=0; i<node_size; i++){
                if(appear.find(i) == appear.end()){
                    appear.insert(i);
                    Q.push({i,i});
                    break;
                }
            }
            ret++;
            goto again;
        }

        return ret;
    }
};

int main(void){
    // vector<vector<int>> isConnected = {{1,1,0},{1,1,0},{0,0,1}};
    vector<vector<int>> isConnected = {{1,0,0,1},{0,1,1,0},{0,1,1,1},{1,0,1,1}};
    Solution s;
    cout<<s.findCircleNum(isConnected)<<endl;
}