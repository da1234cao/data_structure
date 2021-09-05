#include <string>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty())
            return 0;
        string::size_type result = haystack.find(needle); // 找到的子串的首字符位置，或若找不到这种子串则为 npos 。
        if(result == string::npos)
            return -1;
        else
            return int(result);
    }
};