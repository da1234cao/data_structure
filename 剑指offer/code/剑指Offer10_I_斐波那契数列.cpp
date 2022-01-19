#include <vector>

using namespace std;

class Solution {
private:
    int N = 101;
    vector<int> dp;
public:
    Solution(){
        dp.resize(N);
    }

    int fib(int n) {
        // 题目限制0 <= n <= 100s
        if(n<=1)
            return n;

        dp[0] = 0;
        dp[1] = 1;
        for(int i=2; i<=n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};