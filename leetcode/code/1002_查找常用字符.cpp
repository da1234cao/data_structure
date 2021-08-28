#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string> result;

        // 二维数组。每一行用于统计一个字符串的字母出现次数
        vector<vector<int>> letters_statistical(words.size(),vector<int>(26,0));

        // 将字母出现次数，统计入数组
        for(int i=0; i<words.size(); i++){
            for(auto ch : words[i]){
                letters_statistical[i][ch-'a']++;
            }
        }

        // 按列统计。该列中不存在零时，求该列的最小值
        for(int col=0; col<26; col++){
            int min = INT32_MAX;
            int row=0;
            for(; row<words.size(); row++){
                if(letters_statistical[row][col]==0)
                    break;
                min = letters_statistical[row][col] < min ? letters_statistical[row][col] : min;
            }
            if(row==words.size()){
                while(min--)
                    result.push_back(string(1,char('a'+col)));
            }
        }

        return result;
    }
};


int main(void){
    vector<string> words = {"bella","label","roller"};

    Solution s;

    vector<string> result = s.commonChars(words);

    for(auto s : result)
        cout<<s<<" ";
}