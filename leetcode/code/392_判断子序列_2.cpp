#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        // 动态规划
        // 求s和t的最长公共子序列长度。如果这个长度等于s的长度，说明s是t的子序列
        int len1 = s.size();
        int len2 = t.size();
        vector<vector<int>> dp(len1+1,vector<int>(len2+1,0));

        for(int i=1; i<=len1; i++){
            for(int j=1; j<=len2; j++){
                if(s[i-1] == t[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }

        for(auto vec : dp){
            for(auto v : vec)
                cout<<v<<" ";
            cout<<endl;
        }

        return dp[len1][len2] == len1 ? true:false;
    }
};