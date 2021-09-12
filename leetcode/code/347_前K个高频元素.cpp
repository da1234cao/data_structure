#include <vector>
#include <map>
#include <algorithm>
#include <cassert>

using namespace std;

class Solution {
private:
    struct cmp{
        bool operator() (const pair<int,int>& p1,const pair<int,int>& p2){
            // 使用键值对的值进行降序排序
            return p1.second>p2.second;
        } 
    };

public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // const int len = nums.size();
        // assert(len>=k);

        // 统计频率
        map<int,int> statisFreqMap;
        for( int num : nums)
            statisFreqMap[num]++;
        
        // 将统计结果放入vector中，按照频率进行降序排序
        vector<pair<int,int>> statisFreqVec;
        map<int,int>::iterator it=statisFreqMap.begin();
        for(it; it!=statisFreqMap.end(); it++){
            statisFreqVec.push_back(make_pair(it->first,it->second));
        }
        sort(statisFreqVec.begin(),statisFreqVec.end(),cmp());

        // 输出频率最高的前k个元素
        vector<int> result;
        for(int i=0; i<k; i++){
            result.push_back(statisFreqVec[i].first);
        }

        return result;
    }
};