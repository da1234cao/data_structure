#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    int max_scope(const vector<int>& nums, int first, int last){
        // [first，last]闭区间内，最大值
        // 自行确保first，last在nums范围内
        int i = first;
        int max_num = nums[first];
        for(i; i<=last; i++){
            max_num = nums[i] > max_num ? nums[i]:max_num;
        }
        return max_num;
    }

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size()-k+1; // 滑动次数
        assert(n>0);
        vector<int> result;

        // 计算第一组的最大值
        int window_max = max_scope(nums,0,0+k-1);
        result.push_back(window_max);
        int pre_window_max = window_max;

        for(int i=1; i<n; i++){
            if(pre_window_max == nums[i-1]){ // 如果上次的最大值在本次的窗口之外，需要重新计算最大值
                window_max = max_scope(nums,i,i+k-1);
            }else {
                window_max = pre_window_max > nums[i+k-1] ? pre_window_max:nums[i+k-1];
            }
            result.push_back(window_max);
            pre_window_max = window_max;
        }
        
        return  result;
    }
};