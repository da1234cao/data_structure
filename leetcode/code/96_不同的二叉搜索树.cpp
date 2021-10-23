#include <vector>

using namespace std;

class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1,0);
        dp[0] = 1;
        for(int val=1; val<=n; val++){
            for(int i=0; i<val; i++){ // 根据i，将val划分成左右两边。
                dp[val] += dp[i]*dp[val-1-i]; // 两边形状的排列组合，进行累加
            }
            // cout<<dp[val]<<" ";
        }
        return dp[n];
    }
};