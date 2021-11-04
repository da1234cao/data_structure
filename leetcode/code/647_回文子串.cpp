#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        // 动态规划。dp[i,j]表示[i,j]范围是否为回文串。
        // if s[i] == s[j] ,是否为回文串，由dp[i+1][j-1]决定
        // if s[i] != s[j], 不是回文串
        vector<vector<bool>> dp(s.size(),vector<bool>(s.size(),false));
        int result = 0;

        for(int i=s.size()-1; i>=0; i--){
            for(int j=i; j<s.size(); j++){
                if(s[i] == s[j]){
                    if(j-i <= 1){ // 只有一个或两个元素
                        result++;
                        dp[i][j] = true;
                    }else if(dp[i+1][j-1]){
                        result++;
                        dp[i][j] = true;
                    }
                }
            }
        }

        return result;
    }
};