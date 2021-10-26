#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // 动态规划。第i天是否持有股票，受第i-1天的影响
        // 第i天持有股票所得的现金：dp[i][0] = max(dp[i-1][0],dp[i-1][1]-prices[i]); 前一天持有的股票，继续保持。前一天没有股票，买入
        // 第i天没有持有股票所得的最多现金：dp[i][1] = max(dp[i-1][1], dp[i-1][0]+prices[i]); 继续不持有股票。前一天的股票卖掉

        vector<vector<int>> dp(prices.size(),vector<int>(2,0));
        dp[0][0] = -prices[0];
        dp[0][1] = 0;

        for(int i=1; i<prices.size(); i++){
            dp[i][0] = max(dp[i-1][0],dp[i-1][1]-prices[i]);
            dp[i][1] = max(dp[i-1][1], dp[i-1][0]+prices[i]);
        }

        return dp[prices.size()-1][1];
    }
};