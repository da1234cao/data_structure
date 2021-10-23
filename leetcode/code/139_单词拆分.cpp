#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // 动态规划。递推公式：dp[j] = 如果s[0,i-1]可以使用字典中元素组成 && s[i,j-1]的单词在字典中，为true

        int max_word_len = 0;
        for(string& word : wordDict)
            max_word_len = max(max_word_len, (int)word.size());

        // dp[i]:s[0]~s[i-1]是否可以使用字典组成
        unordered_set<string> word_set(wordDict.begin(),wordDict.end());
        vector<bool> dp(s.size()+1,false);
        dp[0] = true; // 在字符串的开头，加上一个空字符。并认为其可以在字典中查找到。要不然不好递推处理。

        for(int j=1; j<=s.size(); j++){ // s[0,j-1]若能由字典组成，设为true
            int i = j<max_word_len ? 0:j-1-max_word_len+1;
            for(; i<=j-1; i++){
                string word = s.substr(i,j-1-i+1);
                if(word_set.find(word)!=word_set.end() && dp[i]){
                    dp[j] = true;
                    break;
                }
            }
        }

        return dp[s.size()];
    }
};