#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // 贪心策略：在波动的低估买入，峰值卖出
        // 策略证明：不放过每个赚钱的机会
        int result = 0;
        int low,high;
        for(int i=0; i<prices.size()-1; i++){
            if(prices[i+1] > prices[i]){ // 在上坡
                low = i;
                while(i<prices.size()-1 && prices[i+1] > prices[i]) // 循环退出时，i在当前坡的峰值
                    i++;
                high = i;
                result += (prices[high] - prices[low]);
            }
        }

        return result;
    }
};