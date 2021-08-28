#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> sLetter(26,0);
        vector<int> tLetter(26,0);

        // 默认都是小写字母

        for(int i=0; s[i]!='\0'; i++){
            if(s[i]>='a' && s[i]<='z')
                sLetter[s[i]-'a']++;
        }

        for(int i=0; t[i]!='\0'; i++){
            if(islower(t[i])){
                tLetter[t[i]-'a']++;
            }
        }

        bool result = true;
        for(int i=0; i<26; i++){
            if(sLetter[i]!=tLetter[i]){
                result = false;
                break;
            }
        }

        return result;
    }
};