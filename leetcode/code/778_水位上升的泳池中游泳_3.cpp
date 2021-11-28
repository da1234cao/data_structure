#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class jointSearchSet {
private:
    int len;
    vector<int> parent;
public:
    jointSearchSet(int n){
        len = n;
        parent.resize(n);
        for(int i=0; i<n; i++)
            parent[i] = i;
    }

    int findRoot(int x){
        // 查找该点所在的集合
        while(parent[x] != x)
            x = parent[x];
        return x;
    }

    bool isConnect(int x, int y){
        // 判断x，y是否在同一个集合
        return findRoot(x) == findRoot(y);
    }

    void unionSet(int x, int y){
        // 所在集合不相交时候，合并两个集合
        if(!isConnect(x,y)){ 
            int root_x = findRoot(x);
            int root_y = findRoot(y);
            parent[root_y] = root_x;
        }
    }

};


class Solution {
private:
    int N;
    vector<vector<int>> DIRECTIONS = {{-1,0},{1,0},{0,-1},{0,1}};

public:
    int swimInWater(vector<vector<int>>& grid) {
        N = grid.size();
        jointSearchSet jss(N*N);

        // 将gird存储为map格式：(高度，位置)，其中位置使用pair存储
        // 题目已经限定，高度不重复的序列
        unordered_map<int,pair<int,int>> grid_map; 
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                grid_map[grid[i][j]] = {i,j};
            }
        }

        // 模拟下雨，threshold
        for(int i=0; i<N*N; i++){
            pair<int,int> loc = grid_map[i];
            int x = loc.first;
            int y = loc.second;

            for(auto dirt : DIRECTIONS){ // 当前高度和四周相连
                int new_x = x + dirt[0];
                int new_y = y + dirt[1];
                if(inArea(new_x, new_y) && grid[new_x][new_y]<=i)
                    jss.unionSet(x*N+y, new_x*N+new_y);
            }

            if(jss.isConnect(0,N*N-1)) //返回当前雨水高度
                return i;
        }

        return -1; // 不会走到这一步。如果走到，说明程序有问题
    }

    bool inArea(int x, int y){
        return (x>=0 && x<N && y>=0 && y<N);
    }
};

int main(void){
    // vector<vector<int>>  grid = {{0,2},{1,3}};
    vector<vector<int>>  grid = {{0,1,2,3,4},{24,23,22,21,5},{12,13,14,15,16},{11,17,18,19,20},{10,9,8,7,6}};
    Solution s;
    cout<<s.swimInWater(grid)<<endl;
}