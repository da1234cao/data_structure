#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> magazineMap; // 存储杂志的字母组成
        for(auto ch : magazine)
            magazineMap[ch]++;
        
        bool flag = true;
        for(auto ch : ransomNote){ // 用杂志中的字母来填充ransomNote
            if(magazineMap.count(ch)==0 || magazineMap[ch]<=0){ // 这个字母不存在，或被用完
                flag = false;
                break;
            }
            magazineMap[ch]--;
        }

        return flag;
    }
};