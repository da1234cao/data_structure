#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result = nums[0]; // 题目保证至少有一个元素
        int pre_sum = nums[0]; 
        for(int i=1; i<nums.size(); i++){
            if(pre_sum < 0) // 如果前面的和不能做贡献，丢弃
                pre_sum = 0;
            pre_sum += nums[i]; // 前面的和可以做贡献，保留
            if(pre_sum > result)
                result = pre_sum;
        }
        return result;
    }
};