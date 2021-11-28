#include <vector>
#include <string>
#include <iostream>

using namespace std;

class unionFind {
private:
    vector<int> parent;
    int cnt;
public:
    unionFind(int n){
        cnt = n;
        parent.resize(n);
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
    int regionsBySlashes(vector<string>& grid) {
        // 将一个单元格拆分成四个部分。先合并单元格内部，在进行单元格之间的合并
        int N = grid.size();
        int size = 4*N*N;
        unionFind uf(size);

        for(int i=0; i<N; i++){
            const string& str = grid[i];
            for(int j=0; j<N; j++){
                int index = 4*(i*N+j); // (i,j)单元格中，编号为0的三角形

                // 单元格内部合并
                switch (str[j]){
                case '/': // 0,3合并；1，2合并
                    uf.unionSet(index, index+3);
                    uf.unionSet(index+1, index+2);
                    break;
                case '\\': // 0,1合并； 2,3合并
                    uf.unionSet(index, index+1);
                    uf.unionSet(index+2, index+3);
                    break;
                case ' ': // 0,1,2,3合并
                    uf.unionSet(index, index+1);
                    uf.unionSet(index+1, index+2);
                    uf.unionSet(index+2, index+3);
                    break;
                default:
                    cout<<"error...";
                    exit(0);
                }


                // 单元格之间的合并：当前单元格中的1，与右侧单元格的3合并；当前单元格的2，与下面单元格的0合并
                if(j+1 < N){
                    int index1 = index+1;
                    int index3 = 4*(i*N+j+1) + 3;
                    uf.unionSet(index1, index3);
                }
                if(i+1 < N){
                    int index2 = index+2;
                    int index0 = 4*((i+1)*N+j);
                    uf.unionSet(index2, index0);
                }

            }
        }

        return uf.getCnt();
    }
};


int main(void){
    // vector<string> grid = {" /","/ "};
    vector<string> grid = {"/\\","\\/"};
    Solution s;
    cout<<s.regionsBySlashes(grid)<<endl;
}