#include <sstream>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string replaceSpace(string s) {
        string result;
        istringstream ss(s);
        char needReplaceAlpha = ' ';
        string substitution = "%20";

        char ch;
        while(ss>>noskipws>>ch){
            if(ch != needReplaceAlpha)
                result+=ch;
            else
                result+=substitution;
        }

        return result;
    }
};

int main(void){
    string s = "We are happy.";
    Solution sol;
    cout<<sol.replaceSpace(s);
}