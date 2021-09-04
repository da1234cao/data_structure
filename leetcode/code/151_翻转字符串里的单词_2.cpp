#include <sstream>
#include <string>
#include <stack>
#include <iostream>
#include <cassert>
#include <algorithm>

using namespace std;

class Solution {
public:
    string deleteExtraSpaces(string s){
        // 使用快慢指针删除字符串中的多余空格：[i,j)范围的内容为多余内容
        if(s.empty())
            return s;

        const int len = s.size();
        int i=0,j=0;

        while(j<len){
            if((s[j]!=' ') || (j-1>=0 && s[j-1]!=' ')) // 合法需要保留的字符("word ")：本身不是空格 || 作为分隔符的空格(本身是空格 && 前一个不是空格)
                s[i++] = s[j++]; 
            else{
                j++;
            }
        }
        if(s[i-1]==' ') // 上面过滤出的是(word )*格式。过滤，最后一个可能是空格，单独处理一下
            i--;

        assert(s[0]!=' ' || s[len-1]!=' ');
        if(i!=len)
            s.resize(i);
            
        return s;
    }

    // string reverseWord(string s, int start, int end){ //[start，end]闭区间翻转
    //     reverse(s.begin()+start,s.begin()+end+1);
    // }

    string reverseWords(string s) {
        if(s.empty())
            return s;

        s = deleteExtraSpaces(s); // 删除多余空格
        reverse(s.begin(),s.end()); // 字符串翻转

        // 翻转单词,[i,j]闭合范围内为一单词
        int i=0,j=0;
        s.push_back(' '); // 统一格式为(word )
        const int len = s.size();
        while(i<len && j<len){
            while(s[j]!=' ') j++;
            reverse(s.begin()+i,s.begin()+j);
            i = j+1;
            j++; 
        }
        s.pop_back(); // 删除最后一个空格

        return s;
    }
};



int main(void){
    string s = "a good   example";
    Solution sol;
    cout<<sol.reverseWords(s);
}