#include <stack>
#include <vector>
#include <string>
#include <cctype>
#include <iostream>
#include <algorithm>

using namespace std;


class Solution {
public:
    int calculator(int num1, int num2, char operation){
        int result;
        switch (operation){
            case '+':
                result = num1+num2;
                break;
            case '-':
                result = num1-num2;
                break;
            case '*':
                result = num1*num2;
                break;
            case '/':
                result = num1/num2;
                break;
            default:
                // perror("not such operation\n");
                exit(1);
        }
        return result;
    }

    int evalRPN(vector<string>& tokens) {
        // 默认输入合法
        stack<int> operand;

        for(string s : tokens){
            // all_of(s.begin(),s.end(),[](char c){return isdigit(c);});
            if(isdigit(s[0]) || (s[0]=='-'&&isdigit(s[1])))
                operand.push(stoi(s));
            else{
                int num2 = operand.top();
                operand.pop();
                int num1 = operand.top();
                operand.pop();
                operand.push(calculator(num1,num2,s[0]));
            }
        }

        return operand.top();
    }
};

int main(void){
    vector<string> tokens = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    Solution s;
    cout<<s.evalRPN(tokens);
}