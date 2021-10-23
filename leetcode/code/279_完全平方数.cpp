#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int numSquares(int n) {
        // 思路：完全背包

        // dp[j]：表示当装入恰好为j时，装入物品最少的数量
        vector<int> dp(n+1,INT_MAX);
        dp[0] = 0; // 当某个数的平方和恰好为目标时，需要用到这个元素

        for(int i=1; i*i<=n ;i++){ // 先遍历物品
            for(int j=i*i; j<=n; j++){ // 再遍历背包；背包从小到大，元素可以重复
                dp[j] = min(dp[j],dp[j-i*i]+1);
            }
        }

        return dp[n];
    }
};
