#include <vector>

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        if(cost.size() == 2) // cost 的长度范围是 [2, 1000]
            return min(cost[0],cost[1]);
        
        int pre_pre = cost[0];
        int pre = cost[1];
        int cur;
        for(int i=2; i<cost.size(); i++){
            cur = min(pre_pre,pre) + cost[i];
            pre_pre = pre;
            pre = cur;
        }

        return min(cur,pre_pre); // 最后一个楼梯可以不选，跳过去
     }
};