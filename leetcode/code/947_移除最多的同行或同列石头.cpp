#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class unionFind {
private:
    int cnt=0;
    unordered_map<int,int> parent;

public:
    int findRoot(int x){
        if(parent.find(x) == parent.end()){ // 该元素没有出现过，先自成一个集合
            parent.insert({x,x});
            cnt++;
            return x;
        }else{
            while(x != parent[x])
                x = parent[x];
            return x;
        }
    }

    bool isConnect(int x, int y){
        return (findRoot(x) == findRoot(y));
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
    int removeStones(vector<vector<int>>& stones) {
        // 同一个元素的(x,y)需要在同一个集合里面
        // 两个不同元素的x相等，或者y相等，在同一个集合里面
        // 避免x与y重复，nex_x = x +10001
        // 为了节省空间，并查集使用map存储
        unionFind uf;
        for(auto stone : stones){
            uf.unionSet(stone[0]+10001, stone[1]);
        }
        return stones.size() - uf.getCnt();
    }
};

int main(void){
    vector<vector<int>> stones = {{0,0},{0,1},{1,0},{1,2},{2,1},{2,2}};
    Solution s;
    cout<<s.removeStones(stones)<<endl;
}