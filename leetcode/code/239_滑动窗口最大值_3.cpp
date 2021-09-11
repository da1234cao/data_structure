#include <vector>
#include <queue>
#include <cassert>

using namespace std;

class Solution {
private:
    struct cmp{
        bool operator () (const pair<int,int>& node1,const pair<int,int>& node2){
            // 不比较第二个元素
            if(node1.first < node2.first)
                return true;
            else
                return false; 
        }
    };

public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // 将元素放入大顶堆。若堆顶元素位于窗口范围内，其为当前窗口中的最大值。
        // 若堆顶元素不在窗口范围内，删除堆顶元素，直到堆顶元素在窗口范围内。
        vector<int> result;
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> priQue;
        const int len = nums.size();

        // 先将前k-1个元素放入堆中
        for(int i=0; i<k-1; i++)
            priQue.emplace(nums[i],i);
        
        for(int i=k-1; i<len; i++){ // i每次向前移动一格
            priQue.emplace(nums[i],i); // 插入一个新元素
            // while(!(priQue.top().second>=(i-k+1) && priQue.top().second<=i)){ // 当大顶堆的堆顶不在范围内，不断移除堆顶
            while(priQue.top().second <= i-k){
                priQue.pop();
            }
            result.push_back(priQue.top().first);
        }

        return result;
    }
};