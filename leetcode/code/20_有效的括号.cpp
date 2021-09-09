#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;

class Solution {
private:
    set<char> all_symbol = {'(',')','{','}','[',']'}; // 需要处理的符号
    set<char> left_symbol = {'(','{','['}; // 触发压栈的符号
    set<char> right_symbol = {')',']','}'}; // 触发匹配的符号
    map<char,char> matchRule = {{')','('},{'}','{'},{']','['}}; ; // 匹配规则

public:
    char matchSymbol(char sym){
        // 自行确保传入的sym来自“触发匹配的符号”
        return matchRule[sym];
    }

    bool isValid(string s) {
        stack<char> readMatchSymbol;
        bool result = true;

        for(auto sym : s){
            if(all_symbol.count(sym)){ // 判断是否为需要处理的符号
                if(left_symbol.count(sym)){ // 是否为需要压栈的符号
                    readMatchSymbol.push(sym);
                }else if(right_symbol.count(sym)){ //是否为需要匹配的符号
                    if(readMatchSymbol.empty()){
                        result = false;
                        break;
                    }
                    if(matchSymbol(sym) != readMatchSymbol.top()){
                        result = false;
                        break;
                    }
                    if(matchSymbol(sym) == readMatchSymbol.top()){
                        readMatchSymbol.pop();
                    }
                }
            }
        }

        return readMatchSymbol.empty()&&result;
    }
};