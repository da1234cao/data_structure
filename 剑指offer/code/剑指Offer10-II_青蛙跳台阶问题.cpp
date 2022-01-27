class Solution {
public:
    int numWays(int n) {
        if(n==0)
            return 1;
        if(n<=2)
            return n;

    // 动态规划：f(n) = f(n-1) + f(n-2)
        int pprev = 1; // 跳上一级台阶的方法
        int prev = 2; // 跳上两级台阶的方法
        int result = 0;
        for(int i=3; i<=n; i++){
            result = (pprev + prev)%1000000007;
            pprev = prev%1000000007;
            prev = result%1000000007;
        }

        return result;
    }
};