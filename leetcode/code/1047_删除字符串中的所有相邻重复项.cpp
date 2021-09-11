#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> noRepeatStr;
        string result;

        for(char ch : s){
            if(noRepeatStr.empty())
                noRepeatStr.push(ch);
            else if(ch == noRepeatStr.top())
                noRepeatStr.pop();
            else
                noRepeatStr.push(ch);
        }

        int len = noRepeatStr.size();
        result.resize(len);
        for(int i=len-1; i>=0; i--){
            result[i] = noRepeatStr.top();
            noRepeatStr.pop();
        }

        return result;
    }
};