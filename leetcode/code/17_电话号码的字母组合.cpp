#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution {
private:
    map<char,vector<char>> rule{
        {'2',{'a','b','c'}},
        {'3',{'d','e','f'}},
        {'4',{'g','h','i'}},
        {'5',{'j','k','l'}},
        {'6',{'m','n','o'}},
        {'7',{'p','q','r','s'}},
        {'8',{'t','u','v'}},
        {'9',{'w','x','y','z'}}
    };

    vector<string> result;
    string s;
    void backTracking(const string& digits, int index){
        // 递归出口
        if(index == digits.size()){
            result.push_back(s);
            return;
        }

        vector<char>& digit_letters = rule[digits[index]];
        for(int i=0; i<digit_letters.size(); i++){ // 横向遍历
            s.push_back(digit_letters[i]);
            backTracking(digits,index+1); // 纵向遍历
            s.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty())
            return {};
        backTracking(digits,0);
        return result;
    }
};