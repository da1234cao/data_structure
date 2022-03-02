#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        // 输入s的长度，大于等于1

        int maxLen = 0;
        int left = 0;
        int right = 0;

        // dp[i,j]，表示s[i,j]字串，是否为回文串
        vector<vector<bool>> dp(s.length(), vector<bool>(s.length(),false));

        for(int i=s.size()-1; i>=0; i--) {
            for(int j=i; j<s.size(); j++) {
                if(s[i] == s[j]) {
                    if( j - i <= 1) { // 自身是回文，两个元素相等是回文
                        dp[i][j] = true; 
                    } else if(dp[i+1][j-1] == true){ // 判断内部是否为回文
                        dp[i][j] = true;
                    }
                }
                // else 不相等，s[i,j]字串，不是为回文串

                if(dp[i][j] == true && (j-i+1)>maxLen) {
                    maxLen = j-i+1;
                    left = i;
                    right = j;
                }
            }
        }

        return s.substr(left,right-left+1);

    }
};