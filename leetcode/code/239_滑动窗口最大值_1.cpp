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

        for(int i=0; i<n; i++){
            result.push_back(max_scope(nums,i,i+k-1));
        }
        
        return  result;
    }
};