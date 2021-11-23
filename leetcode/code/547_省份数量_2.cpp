#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    void recursive(vector<vector<int>>& isConnected, unordered_set<int>& appeared, int row){
        // 深度遍历一个连通图
        for(int i=0; i<isConnected.size(); i++){
            if(isConnected[row][i]==1 && appeared.find(i) == appeared.end()){
                appeared.insert(i);
                recursive(isConnected,appeared,i);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int ret = 0;
        unordered_set<int> appeared;
        for(int i=0; i<isConnected.size(); i++){ // 遍历所有的节点
            if(appeared.find(i) == appeared.end()){
                ret++;
                recursive(isConnected,appeared,i);
            }
        }
        return ret;
    }
};