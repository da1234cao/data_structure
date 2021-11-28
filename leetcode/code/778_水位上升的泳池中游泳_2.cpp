#include <iostream>
#include <queue>

using namespace std;

class Solution {
    // 二分查找+广度遍历
private:
    vector<vector<int>> DIRECTIONS = {{-1,0},{1,0},{0,-1},{0,1}};

    bool bfs(vector<vector<int>>& grid, int threshold){
        // 从(0,0) -> (N-1,N-1);限制条件为threshold

        // 第一个点是否满足条件
        if(grid[0][0] > threshold)
            return false;
        
        int N = grid.size();
        vector<vector<bool>> visited(N,vector<bool>(N,false));
        queue<pair<int,int>> Q;
        visited[0][0] = true;
        Q.push({0,0});

        while(!Q.empty()){
            pair<int,int> loc = Q.front();
            Q.pop();
            int x = loc.first;
            int y = loc.second;

            if(x == N-1 && y == N-1)
                return true;

            for(auto dirt : DIRECTIONS){
                int new_x = x + dirt[0];
                int new_y = y + dirt[1];
                if(inArea(grid,new_x,new_y) && !visited[new_x][new_y] && grid[new_x][new_y]<=threshold){
                    visited[new_x][new_y] = true;
                    Q.push({new_x,new_y});
                }
            }
        }

        return false;

    }

    bool inArea(vector<vector<int>>& grid, int x, int y){
        // 判断(x,y)是否在网格中
        int N = grid.size();
        return (x>=0 && x<N && y>=0 && y<N) ? true:false;
    }

public:
    int swimInWater(vector<vector<int>>& grid) {
        int N = grid.size();
        int left = 0;
        int right = N*N-1;

        while(left < right){
            int mid = (left+right)/2;
            int ret = bfs(grid,mid);
            if(ret == true)
                right = mid;
            else
                left = mid + 1;
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