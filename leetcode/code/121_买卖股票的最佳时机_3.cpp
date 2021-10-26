#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // 动态规划：
        // dp[i][0] 表示第i天持有股票所得最多现金(继续持有原来股票，买入新股票)，dp[i][0] = max(dp[i - 1][0], -prices[i]);
        // dp[i][1] 表示第i天不持有股票所得最多现金(继续保持手上没有股票,原来手上有股票卖出)，dp[i][1] = max(dp[i - 1][1], prices[i] + dp[i - 1][0])
        // 本质(和贪心相同)：dp[i][0]维护一个最小股票值；dp[i][1]维护一个最大的上升。

        // 所以我们修改下递推公式
        // 维护一个最小股票值：dp[i][0] = min(dp[i-1][0],prices[i]);
        // 维护一个最大上升：dp[i][1] = max(dp[i-1][1],prices[i]-dp[i][0])
        int len = prices.size();
        if(len == 0) return 0;
        vector<vector<int>> dp(len,vector<int>(2,0));
        dp[0][0] = prices[0];
        dp[0][1] = 0;
        for(int i=1; i<len; i++){
            dp[i][0] = min(dp[i-1][0],prices[i]);
            dp[i][1] = max(dp[i-1][1],prices[i]-dp[i][0]);
        }

        return dp[len-1][1];
    }
};