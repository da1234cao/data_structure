#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        // 除去边缘数字，满足公式dp[i][j] = dp[i-1][j] + dp[i-1][j-1]
        vector<vector<int>> dp(numRows);

        for(int i=0; i<numRows; i++){
            int n = i+1; // 该行有i+1个数字
            dp[i].resize(n);
            dp[i][0] = 1; // 边缘数字初始化为零
            dp[i][n-1] = 1;
            
            for(int j=1; j<n-1; j++){ // 非边缘数字满足上面公式
                dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
            }
        }

        return dp;
    }
};