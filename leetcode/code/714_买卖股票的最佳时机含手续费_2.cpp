#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        // dp[i][0]状态一，持有股票,保持持有股票 or 手上没有股票并此时买入 dp[i][0] = max(dp[i-1][0], dp[i-1][1]-prices[i])
        // dp[i][1]状态二，不持有股票，继续不持有股票 or 卖掉手上股票 dp[i][1] = max(dp[i-1][1], dp[i-1][0]+prices[i]-fee)
        // 这两种状态之间的转换，可以包含所以情况。取max时，为最优。

        vector<vector<int>> dp(prices.size(), vector<int>(2,0));
        dp[0][0] = -prices[0];

        for(int i=1; i<prices.size(); i++){
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]-prices[i]);
            dp[i][1] = max(dp[i-1][1], dp[i-1][0]+prices[i]-fee);
        }

        return dp[prices.size()-1][1];
    }
};