#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size()+1,vector<int>(word2.size()+1,0));
        // 初始化。从当前串变成空串
        for(int i=0; i<=word1.size(); i++){
            dp[i][0] = i;
        }
        for(int i=0; i<=word2.size(); i++){
            dp[0][i] = i;
        }

        for(int i=1; i<=word1.size(); i++){
            for(int j=1; j<=word2.size(); j++){
                if(word1[i-1] == word2[j-1])
                    dp[i][j] = dp[i-1][j-1]; // 不需要做修改
                else
                    dp[i][j] = min(dp[i-1][j-1]+1, min(dp[i-1][j]+1, dp[i][j-1]+1)); 
                    // 分别为修改最后一个字符；对与A的第i个字符，B在后面添加一个字符；对于B的第j个字符，在A的后面添加一个字符
            }
        }

        return dp[word1.size()][word2.size()];
    }
};