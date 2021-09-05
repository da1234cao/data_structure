#include <string>

using namespace std;

class Solution {
public:
    string reverseLeftWords(string s, int n) {
        int s1Len = n;
        int s2Len = s.size()-n;

        string s1 = s.substr(0,s1Len);
        string s2 = s.substr(s1Len,s2Len);

        return s2+s1;
    }
};