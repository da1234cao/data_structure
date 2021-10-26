#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // dp[i][0]状态一,买入股票, 保持之前买入的股票 or 之前没有买股票今天买 dp[i][0] = max(dp[i-1][0], max(dp[i-1][1],dp[i-1][3])-prices[i])
        // dp[i][1]状态二，卖出股票，已度过冷冻期 dp[i][1] = max(dp[i-1][0], dp[i-1][3])
        // dp[i][2]状态三，卖出股票，今天卖 dp[i][2] = dp[i-1][0]+prices[i]
        // dp[i][3]状态四，今天为冷冻期 dp[i][3] = dp[i-1][2]

        vector<vector<int>> dp(prices.size(), vector<int>(4,0));
        dp[0][0] = -prices[0];

        for(int i=1; i<prices.size(); i++){
            dp[i][0] = max(dp[i-1][0], max(dp[i-1][1],dp[i-1][3])-prices[i]);
            dp[i][1] = max(dp[i-1][1], dp[i-1][3]);
            dp[i][2] = dp[i-1][0]+prices[i];
            dp[i][3] = dp[i-1][2];
        }

        return max(dp[prices.size() - 1][3],max(dp[prices.size() - 1][1], dp[prices.size() - 1][2]));
    }
};