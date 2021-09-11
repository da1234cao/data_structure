#include <vector>
#include <queue>
#include <cassert>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // 移除必然不会成为窗口最大值的元素，其余元素放入单调递减队列中
        // 从队头取元素。若队头元素不在窗口范围内，说明该队头元素不在有用，丢弃。
        deque<int> dq; 
        const int len = nums.size();
        vector<int> result;

        // 将前k-1个元素中，可能成为窗口最大值的元素，放入单调队列中
        for(int i=0; i<k-1; i++){
            while(!dq.empty() && nums[i]>nums[dq.back()])
                dq.pop_back();
            dq.push_back(i);
        }

        // 现在，窗口每次移动一格
        for(int i=k-1; i<len; i++){
            // 队列尾部插入一个元素(并，移除必然不会成为窗口最大值的元素)
            while(!dq.empty() && nums[i]>nums[dq.back()])
                dq.pop_back();
            dq.push_back(i);

            // 从队头取元素。若队头元素不在窗口范围内，说明该队头元素不在有用，丢弃。
            while(!dq.empty() && dq.front()<i-k+1)
                dq.pop_front();
            result.push_back(nums[dq.front()]);
        }

        return result;
    }
};