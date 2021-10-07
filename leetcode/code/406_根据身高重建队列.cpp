#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    struct cmp{
        bool operator() (const vector<int>& v1, const vector<int>& v2){
            if(v1[0] > v2[0])
                return true;
            else if(v1[0] == v2[0])
                return v1[1] < v2[1];
            else
                return false;
        }
    };

    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        // people[i] = [hi, ki] 表示第 i 个人的身高为 hi ，前面 正好 有 ki 个身高大于或等于 hi 的人。
        // hi大者在前。hi相同，ki小者在前
        sort(people.begin(),people.end(),cmp());

        vector<vector<int>> result;

        for(vector<int> p : people){
            int count = 0;
            if(p[1] == count) // 未插入的身高最高的人，且他的前面没有身高大于等于他的人，插入在目前的最前方
                result.insert(result.begin(),p);
            else{
                for(int i=0; i<result.size(); i++){
                    if(p[0] <= result[i][0])
                        count++;
                    if(count == p[1]){ // 前面有p[1]个身高大于等于自身身高，插入
                        result.insert(result.begin()+i+1,p);
                        break;
                    }
                }
            }
        }

        return result;
    }
};


int main(void){
    vector<vector<int>> peopele = {{7,0},{4,4},{7,1},{5,0},{6,1},{5,2}};
    Solution s;
    vector<vector<int>> result = s.reconstructQueue(peopele);
    for(auto v : result){
        cout<<"{"<<v[0]<<","<<v[1]<<"}";
    }
}