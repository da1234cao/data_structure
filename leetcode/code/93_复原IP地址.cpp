#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
private:
    vector<string> result;
    vector<string> path;
    void backTracking(const string& s, int startIndex=0){
        // 递归出口
        if(path.size() == 4 && startIndex>=s.size()){
            string IPv4;
            for(auto str : path){
                IPv4 += str;
                IPv4 +='.';
            }
            IPv4.pop_back();
            result.push_back(IPv4);
            // cout<<IPv4<<endl;
            return;
        }else if(path.size() == 4 && startIndex<s.size())
            return;

        const int start = startIndex;
        const int end = start+2 < s.size() ? start+2:s.size()-1; // IP地址的每个数字最多三位

        for(int i=start; i<=end ; i++){
            string num_str(s.begin()+start,s.begin()+i+1);
            if(s[start]-'0' == 0 && i == start)
                path.push_back("0");
            else if(s[start]-'0' == 0 && i != start)
                continue;
            else if(stoi(num_str) <= 255) // 由1~3位构成的数字范围，应当[0,255]范围
                path.push_back(num_str);
            else // 大于255，直接返回
                continue;// return;

            backTracking(s,i+1);
            path.pop_back();
        }
    }

public:
    vector<string> restoreIpAddresses(string s) {
        backTracking(s);
        return result;
    }
};

int main(void){
    string s = "101023";
    Solution sol;
    vector<string> result = sol.restoreIpAddresses(s);
    for(auto IPv4 : result){
        cout<<IPv4<<" ";
        cout<<endl;
    } 
}