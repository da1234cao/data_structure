#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();
        vector<vector<int>> dp(row,vector<int>(col,0));

        // 初始化上边界和左边界
        for(int i=0; i<col && obstacleGrid[0][i]!=1; i++)
            dp[0][i] = 1;
        for(int i=0; i<row && obstacleGrid[i][0]!=1; i++)
            dp[i][0] = 1;
        
        for(int i=1; i<row; i++){
            for(int j=1; j<col; j++){
                if(obstacleGrid[i][j] == 1)
                    dp[i][j] = 0; // 这里可以不用赋值，因为初始化已为零
                else
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }

        return dp[row-1][col-1];
    }
};