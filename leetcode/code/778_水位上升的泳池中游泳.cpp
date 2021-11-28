#include <iostream>
#include <vector>

using namespace std;

class Solution {
    // 二分查找+深度遍历
private:
    const vector<vector<int>> DIRECTION = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // 上下左右四个方向

    bool inArea(int x, int y, const vector<vector<int>>& grid){
        // 确保位置在表格内
        int N = grid.size();
        return (x>=0 && x<N && y>=0 && y<N) ? true:false;
    }

    void dfs(const vector<vector<int>>& grid, int x, int y, vector<vector<bool>>& visited, const int& threshold, bool& ret){
        // 在threshold条件下，判断能否从(x,y)深度遍历到(N-1,N-1)
        int N = grid.size();

        // 递归出口
        if(ret == true)
            return;
        if(x==N-1 && y==N-1 && !visited[x][y] && grid[x][y]<=threshold){
            ret = true; // 深度遍历到一条合适路径，便层层返回
            return;
        }

        if(inArea(x,y,grid) && !visited[x][y] && grid[x][y]<=threshold)
            visited[x][y] = true;
        else 
            return;
        
        for(auto dirt : DIRECTION){ // 深度遍历四个方向
            int new_x = x + dirt[0];
            int new_y = y + dirt[1];
            if(ret == true)
                return;
            if(inArea(new_x,new_y,grid) && !visited[new_x][new_y] && grid[new_x][new_y]<=threshold)
                dfs(grid, new_x, new_y, visited, threshold, ret);
        }
    }

public:
    int swimInWater(vector<vector<int>>& grid) {
        int N = grid.size();
        int left = 0;
        int right = N*N - 1;

        while (left < right){
            int mid = (right+left)/2; // 注意溢出情况
            vector<vector<bool>> visited(N,vector<bool>(N,false));
            bool ret = false;
            dfs(grid,0,0,visited,mid,ret); // 深度遍历，查看mid条件下，有无到达终点的路径。结果保存在ret中
            if(ret == true)
                right = mid;
            else
                left = mid+1;
        }

        return left;   
    }
};

int main(void){
    // vector<vector<int>>  grid = {{0,2},{1,3}};
    vector<vector<int>>  grid = {{0,1,2,3,4},{24,23,22,21,5},{12,13,14,15,16},{11,17,18,19,20},{10,9,8,7,6}};
    Solution s;
    cout<<s.swimInWater(grid)<<endl;
}