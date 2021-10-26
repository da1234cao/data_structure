#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // 动态规划；状态转移
        // 某一天的状态：没有操作；第一次买入；第一次卖出；第二次买入；第二次卖出
        // dp[i][1]，表示的是第i天，买入股票的状态，并不是说一定要第i天买入股票
        // 继续保持没有操作状态：dp[i][0] = dp[i-1][0];
        // 继续保持第一次买入状态 or 之前没买现在第一次买入：dp[i][1] = max(dp[i-1][1],dp[i-1][0]-prices[i])
        // 继续保持第一次卖出状态 or 之前没卖出在第一次卖出：dp[i][2] = max(dp[i-1][2],dp[i-1][1]+prices[i])
        // 继续保持第二次买入状态 or 之前卖出一次现在第二次买入：dp[i][3] = max(dp[i-1][3],dp[i-1][2]-prices[i])
        // 继续保持第二次卖出状态 or 之前第二次买入现在第二次卖出：dp[i][4] = max(dp[i-1][4],dp[i-1][3]+prices[i])

        vector<vector<int>> dp(prices.size(),vector<int>(5,0));
        // 第一行，第一列的其他元素初始化为0
        dp[0][1] = -prices[0];
        dp[0][3] = -prices[0]; // 这个初始化需要看左边的一个和上面的一个，但是上面没有；答案是买入/卖出/再买入;很难理解哦

        for(int i=1; i<prices.size(); i++){
            // 当前状态，由上一个和左边一个决定
            // 可以买卖一次，可以买卖两次，也可以不买卖
            dp[i][1] = max(dp[i-1][1],dp[i-1][0]-prices[i]);
            dp[i][2] = max(dp[i-1][2],dp[i-1][1]+prices[i]);
            dp[i][3] = max(dp[i-1][3],dp[i-1][2]-prices[i]);
            dp[i][4] = max(dp[i-1][4],dp[i-1][3]+prices[i]);
        }

        for(auto vec : dp){
            for(auto v:vec){
                cout.width(3);
                cout<<v<<" ";
            }
            cout<<endl;
        }

        return dp[prices.size()-1][4];
    }
};

int main(void){
    // vector<int> prices = {3,3,5,0,0,3,1,4};  // 买卖两次
    vector<int> prices = {7,6,8,3,1}; // 买卖一次
    // vector<int> prices = {7,6,4,3,1};  // 不买卖
    Solution s;
    cout<<s.maxProfit(prices)<<endl;
}