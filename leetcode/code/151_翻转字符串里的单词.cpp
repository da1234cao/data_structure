#include <sstream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        istringstream ss(s);
        stack<string> st;
        string result;

        // 当一句话中的单词全部压栈
        string word;
        while(ss>>word){
            st.push(word);
            st.push(" "); // 压入一个空格
        }
        st.pop();

        // 弹栈到result中
        while(!st.empty()){
            result+=st.top();
            st.pop();
        }

        return result;
    }
};