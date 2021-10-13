#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        // S的长度在[1, 500]之间。S只包含小写字母 'a' 到 'z' 。
        vector<int> result;
        int start = 0, tmp_end, end; // 分别表示：切割区间的开始位置，和开始字符相同的最后一个字符位置，切割区间的最后一个位置

        for(int i=start; i<s.size(); ){

            for(int j=s.size()-1; j>=start; j--){ // 从后向前，找到和开始切割字符相同字符的最后位置
                if(s[j] == s[start]){
                    tmp_end = j;
                    break;
                }
            }

            set<char> appr; // 记录[start,tmp_end]这个闭区间出现过的字符
            set<char> appr_new;
            for(int j=start; j<=tmp_end; j++){
                appr.insert(s[j]);
            }

fixEnd:
            for(int j=s.size()-1; j>=tmp_end; j--){ // 修正切割区间的终点，修正为区间中元素出现的最远位置
                if(appr.count(s[j])){
                    end = j;
                    break;
                }
            }

            // 因为，[tmp_end+1,end-1]闭区间，可能出现不在appr中的新元素。所以需要重复修正，直到，[tmp_end+1,end-1]中的元素都出现在appr中
            for(int j=tmp_end+1; j<=end-1; j++){
                if(!appr.count(s[j])){
                    appr_new.insert(s[j]);
                    appr.insert(s[j]);
                }
            }

            if(appr_new.empty())
                ;
            else{
                tmp_end = end;
                appr_new.clear();
                goto fixEnd;
            }

            result.push_back(end-start+1);
            start = end + 1;
            i = start;
        }

        return result;
    }
};

int main(void){
    string s = "qiejxqfnqceocmy";
    Solution sol;
    vector<int> result = sol.partitionLabels(s);
    for(int l : result)
        cout<<l<<" ";
}