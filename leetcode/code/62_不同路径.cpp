#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> maze(m,vector<int>(n,0));
        
        // 对上边界和左边界初始化
        maze[0][0] = 0;
        for(int i=1; i<n; i++)
            maze[0][i] = maze[0][i-1] + 1;
        for(int i=1; i<m; i++)
            maze[i][0] = maze[i-1][0] + 1;

        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                maze[i][j] = min(maze[i-1][j],maze[i][j-1]) + 1;
            }
        }

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                cout<<maze[i][j]<<" ";
            }
            cout<<endl;
        }

        return maze[m-1][n-1];
    }
};

int main(void){
    int m=3, n=7;
    Solution s;
    cout<<s.uniquePaths(m,n)<<endl;
}