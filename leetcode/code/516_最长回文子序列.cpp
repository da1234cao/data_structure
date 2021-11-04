#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string r_s(s);
        reverse(r_s.begin(),r_s.end());

        // 最长回文子序列，转换成，求s和r_s的最长公共子序列
        vector<vector<int>> dp(s.size()+1,vector<int>(s.size()+1,0));

        for(int i=1; i<=s.size(); i++){
            for(int j=1; j<=r_s.size(); j++){
                if(s[i-1] == r_s[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }

        return dp[s.size()][r_s.size()];
    }
};