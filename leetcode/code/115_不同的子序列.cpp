#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        // 动态规划。dp[i][j]表示：s[0,i-1]和t[0,j-1],s出现在t中的个数
        // s[i-1] == t[j-1] --> dp[i][j] = dp[i-1][j-1] + dp[i-1][j] ; 使用s[i-1]匹配的个数+不使用s[i-1]匹配的个数
        // s[i-1] != t[j-1] --> dp[i][j] = dp[i-1][j];
        // vector<vector<int>> dp(s.size()+1, vector<int>(t.size()+1,0)); // 有符号范围不够大，会溢出
        vector<vector<uint64_t>> dp(s.size() + 1, vector<uint64_t>(t.size() + 1));
        // 初始化
        // 初始化第一列为1：当t的第一个元素与s中的元素相等时候，加上左上方的数字(位于第一列)，所以设置为1
        // 初始化第一行抛开第一个元素，为零
        for(int i=0; i<s.size(); i++){
            dp[i][0] = 1;
        }

        for(int i=1; i<=s.size(); i++){
            for(int j=1; j<=t.size(); j++){
                if(s[i-1] == t[j-1])
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }

        return dp[s.size()][t.size()];
    }
};