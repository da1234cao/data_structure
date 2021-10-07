#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() == 1) // 只有一个元素，不用前进，到达重点
            return 0;
        
        int start = 0;
        int end = start + nums[start];
        int farthest_loc = end;
        int count = 1;
        if(farthest_loc >= nums.size()-1) // 终点在一级火箭的打击范围内
            return count;
        
        while(1){ // 题目限定：总是可以到达数组的最后一个位置
            count++; // 每进入一次循环，代表着使用新的打击范围
            for(int i=start+1; i<=end; i++){ // 下一级火箭，所能打击的最大范围
                farthest_loc = max(farthest_loc,nums[i]+i);
                if(farthest_loc >= nums.size()-1)
                    return count;
            }
            start = end;
            end = farthest_loc;
        }
    }
};