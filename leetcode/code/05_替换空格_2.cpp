#include <sstream>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string replaceSpace(string s) {
        char needReplaceAlpha = ' ';
        string substitution = "%20";

        int oldSize = s.size();

        // 统计需要替换的字符串个数
        int count=0;
        for(auto ch : s){
            if(ch == needReplaceAlpha)
                count++;
        }        

        // 调整字符串的大小
        s.resize(s.size()+count*substitution.size()-count);
        int newSize = s.size();

        // 自行替换操作
        int i = oldSize-1; 
        int j = newSize-1;
        while(i >= 0){
            if(s[i] != needReplaceAlpha){
                s[j] = s[i];
                j--;
                i--;
            }else{
                for(auto it = substitution.rbegin(); it!=substitution.rend(); it++)
                    s[j--] = *it;
                i--;
            }
        }

        return s;
    }
};

int main(void){
    string s = "We are happy.";
    Solution sol;
    cout<<sol.replaceSpace(s);
}