#include <vector>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        // 递推公式：dp[i] = dp[i-1] + dp[i-2] (i>=3)
        if(n==1)
            return 1;
        if(n==2)
            return 2;
        
        int pre_pre = 1, pre = 2;
        int cur;
        for(int i=3; i<=n; i++){
            cur = pre_pre + pre;
            pre_pre = pre;
            pre = cur;
        }
        
        return cur;
    }
};