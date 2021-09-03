#include <sstream>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string replaceSpace(string s) {
        string result;
        istringstream ss(s);

        string tmp;
        while(ss>>tmp){
            result+=tmp;
            result+="%20";
        }
        result.erase(result.end()-3,result.end());

        return result;
    }
};

int main(void){
    string s = "We are happy.";
    Solution sol;
    cout<<sol.replaceSpace(s);
}