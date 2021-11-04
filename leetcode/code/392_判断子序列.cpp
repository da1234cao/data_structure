#include <string>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        // 贪心：按照s中字母出现的顺序，遍历t即可。
        // 贪心证明：同一个字母，早出现，包含晚出现
        int index = 0;
        bool flag = true;
        for(int i=0; i<s.size(); i++){
            bool find = false;
            for(index; index<t.size(); index++){
                if(t[index] == s[i]){
                    find = true;
                    index++;
                    break;
                }
            }
            if(find == false){
                flag = false;
                break;
            }
        }
        return flag;
    }
};