#include <vector>
#include <map>
#include <algorithm>
#include <cassert>
#include <queue>
#include <iostream>

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
        
        // 小顶堆，遍历过程中，维护前k大个元素
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> freqQueue; 
        map<int,int>::iterator it = statisFreqMap.begin();

        // 预放置前k个元素
        for(int i=0; i<k; i++){
            freqQueue.push(make_pair(it->first,it->second));
            it++;
        }

        // 向小顶堆中插入一个元素，再删除堆顶最小的元素
        for(int i=k; i<statisFreqMap.size(); i++){
            freqQueue.push(make_pair(it->first,it->second));
            it++;
            freqQueue.pop();
        }

        // 将前k大个元素输出
        vector<int> result;
        while(!freqQueue.empty()){
            result.push_back(freqQueue.top().first);
            freqQueue.pop();
        }
        reverse(result.begin(),result.end()); 

        return result;
    }
};

int main(void){
    vector<int> nums = {3,2,3,1,2,4,5,5,6,7,7,8,2,3,1,1,1,10,11,5,6,2,4,7,8,5,6};
    int k = 10;
    Solution s;
    vector<int> result = s.topKFrequent(nums,k);
    for(int num : result)
        cout<<num<<" ";
}