#include <vector>
#include <iostream>

using namespace std;

class unionFind {
private:
    vector<int> parent;
    int cnt;
public:
    unionFind(int n){
        parent.resize(n);
        cnt = n;
        for(int i=0; i<n; i++)
            parent[i] = i;
    }

    int findRoot(int x){
        while(x != parent[x])
            x = parent[x];
        return x;
    }

    bool isConnect(int x, int y){
        int root_x = findRoot(x);
        int root_y = findRoot(y);
        return root_x == root_y;
    }

    void unionSet(int x, int y){
        int root_x = findRoot(x);
        int root_y = findRoot(y);
        if(root_x == root_y){
            ;
        }else{
            parent[root_x] = root_y;
            cnt--;
        }
    }

    int getCnt(void){
        return cnt;
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n-1) // 至少包含n-1条边，否则返回-1
            return -1;
        
        unionFind uf(n);
        for(auto conn : connections){
            uf.unionSet(conn[0],conn[1]);
        }

        return uf.getCnt()-1; // 返回集合数量-1
    }
};


int main(void){
    vector<vector<int>> connections = {{0,1},{0,2},{0,3},{1,2},{1,3}};
    int n = 6;
    Solution sol;
    cout<<sol.makeConnected(n,connections)<<endl;
}