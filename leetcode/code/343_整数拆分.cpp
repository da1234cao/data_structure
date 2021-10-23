#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        // 题目限定2<=n<=58
        if(n==2)
            return 1;
        if(n==3)
            return 2;

        vector<int> dp(n+1,0);
        dp[2] = 1;
        dp[3] = 2; // 初始化：脱离需要分解成1的部分

        
        for(int val=4; val<=n; val++){
            int max_dp = 0;
            for(int i=2; i<=val/2; i++){ // 将val拆分
                int tmp = max(i,dp[i])*max(val-i,dp[val-i]); // 使用max，判断是否需要进一步拆分；当前拆分结果保存为tmp
                max_dp = max(max_dp, tmp);
            }
            dp[val] = max_dp;
        }

        // for(int i=0; i<dp.size(); i++)
        //     cout<<dp[i]<<" ";

        return dp[n];
    }
};