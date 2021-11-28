#include <vector>
#include <iostream>

using namespace std;

class UnionFind {
private:
    vector<int> parent; // 存储并查集
    vector<int> size; // size[i]存储以i节点为根的集合的大小
public:
    UnionFind(int n){
        parent.resize(n);
        size.resize(n);
        for(int i=0; i<n; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }

    // 查找所在集合的根节点
    int findRoot(int x){
        while(x != parent[x])
            x = parent[x];
        return x;
    }

    // 判断两个节点是否在一个集合里面
    bool isConnect(int x, int y){
        return findRoot(x) == findRoot(y);
    }

    // 集合合并.将x集合合并到y上
    void unionSet(int x, int y){
        int root_x = findRoot(x);
        int root_y = findRoot(y);
        if(root_x == root_y){
            ;
        }else{
            parent[root_x] = root_y;
            size[root_y] += size[root_x];
        }
    }

    // 返回节点x所在集合的元素个数
    int getSize(int x){
        int root_x = findRoot(x);
        return size[root_x];
    }
};


class Solution {
private:
    int rows;
    int cols;
    vector<vector<int>> DIRECTIONS = {{-1,0}, {1,0}, {0,-1}, {0,1}};

    int getIndex(int x, int y){
        return x*cols + y;
    }
    
    bool inArea(int x, int y){
        return (x>=0 && x<rows && y>=0 && y<cols);
    }

public:
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        // 核心思路：去除hits --> 建立并查集 --> 反向添加hits，统计差异

        // 第一步：拷贝grid->copy
        rows = grid.size();
        cols = grid[0].size();
        vector<vector<int>> copy(rows,vector<int>(cols,0));
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++)
                copy[i][j] = grid[i][j];
        }

        // 第二步：去除hits
        for(auto hit : hits){
            copy[hit[0]][hit[1]] = 0;
        }

        // 第三步：建立copy的并查集
        UnionFind uf(rows*cols+1);
        
        //// 给所有的顶部元素添加默认的(虚拟)根节点
        for(int j=0; j<cols; j++){
            if(copy[0][j] == 1)
                uf.unionSet(getIndex(0,j), rows*cols);
        }

        //// 建立并查集。从上向下，从左向右遍历。所以当上方、左侧存在元素的时候，进行合并操作。四周没有元素，默认自成一个集合
        for(int i=1; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(copy[i][j] == 1){
                    if(copy[i-1][j] == 1)
                        uf.unionSet(getIndex(i-1,j), getIndex(i,j));
                    if(j>0 && copy[i][j-1]==1)
                        uf.unionSet(getIndex(i,j-1), getIndex(i,j));
                }
            }
        }

        // 第四步：反向添加hits。反向操作，可以不被前面的hit干扰
        int hitsLen = hits.size();
        vector<int> result(hitsLen,0);
        for(int i=hitsLen-1; i>=0; i--){
            int x = hits[i][0];
            int y = hits[i][1];

            if(grid[x][y] == 0) // 原本没有砖，啥也敲不了
                continue;
            
            int origin = uf.getSize(rows*cols); // 当前与顶部相连砖块个数

            if(x == 0) // 第一行与虚拟根节点相连。与第三步中的内容相同
                uf.unionSet(getIndex(x,y),rows*cols);

            copy[x][y] = 1; // 并将四周元素连接起来；本次补上砖块的连接，仅对本次敲击有作用
            for(auto dirt : DIRECTIONS){
                int new_x = x + dirt[0];
                int new_y = y + dirt[1];
                if(inArea(new_x,new_y) && copy[new_x][new_y]==1){
                    uf.unionSet(getIndex(x,y),getIndex(new_x,new_y));
                }
            }
            int current = uf.getSize(rows*cols);

            // (current - origin -1)等于-1表示补上砖块后，没有连上顶部；等于0表示敲击，只把自己消灭，没有掉落；其中都算上了虚拟节点，相减不影响
            result[i] = (current - origin -1) == -1 ? 0:(current - origin -1); 
        }

        return result;

    }
};

int main(void){
    vector<vector<int>> grid = {{1,0,1},{1,1,1}};
    vector<vector<int>> hits = {{0,0},{0,2},{1,1}};

    // vector<vector<int>> grid = {{1,0,0,0},{1,1,0,0}}; 
    // vector<vector<int>> hits = {{1,1},{1,0}};

    Solution s;
    vector<int> result = s.hitBricks(grid,hits);
    for(auto i : result)
        cout<<i<<" ";
    cout<<endl;
}