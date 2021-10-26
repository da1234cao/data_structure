#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // 维护一个最小值；维护一个最大上升
        // 注意：最大上升，不一定是在最小值时求得；
        int low = INT_MAX;
        int max_profit = 0;
        for(int i=0; i<prices.size(); i++){
            low = min(low,prices[i]);
            if(low != prices[i])
                max_profit = max(max_profit,prices[i]-low);
        }
        return max_profit;
    }
};