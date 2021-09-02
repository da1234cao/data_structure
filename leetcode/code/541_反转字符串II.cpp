#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        string result;
        int reverseNum = s.size()/(2*k);
        int leaveNum = s.size()%(2*k) >= k ? 1 : 0 ; // 剩余字符小于2k&&大于等于k，用1标识；小于k用0标识。

        // 每2k个字符，翻转前k个
        for(int i=0; i<reverseNum; i++){
            reverse_copy(s.begin()+i*2*k,s.begin()+i*2*k+k,back_inserter(result));
            copy(s.begin()+i*2*k+k,s.begin()+i*2*k+2*k,back_inserter(result));
        }

        // 处理剩余的字符
        if(leaveNum == 0){ // 剩余字符<k
            reverse_copy(s.begin()+reverseNum*2*k,s.end(),back_inserter(result));
        }else{ // k<=剩余字符<2k
            reverse_copy(s.begin()+reverseNum*2*k,s.begin()+reverseNum*2*k+k,back_inserter(result));
            copy(s.begin()+reverseNum*2*k+k,s.end(),back_inserter(result));
        }

        return result;
    }
};