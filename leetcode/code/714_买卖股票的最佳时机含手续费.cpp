#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int profit = 0;
        
        // 买入的时候，将手续费算上
        int buy = prices[0] + fee; // 题目保证1 <= prices.length <= 5 * 10^4
        for(int i=0; i<prices.size(); i++){
            if(prices[i]+fee < buy){
                buy = prices[i] + fee; // 以最低的价格买入点
            }else if(prices[i] > buy){
                profit += prices[i]-buy; // 累计收益
                buy = prices[i];  // 如果是在峰顶卖出，下次直接进入if分支，更新buf
                                  // 如果不上升坡，非峰顶卖出，相当于本次没卖profit = (prices[i+1]-prices[i])+(prices[i]-buy) = prices[i+1]-buy
                                  // 连续卖出，相当于，只有第一笔需要手续费；这个代码技巧就很厉害了
            }
            
        }

        return profit;
    }
};