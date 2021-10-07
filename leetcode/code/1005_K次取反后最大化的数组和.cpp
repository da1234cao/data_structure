#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end()); // 从低到高排序

        int zero_lower_bound = lower_bound(nums.begin(),nums.end(),0) - nums.begin(); // 返回第一个大于等于0的位置

        if(k < zero_lower_bound+1){ // 全部用于将将负数变为整数
            for(int i=0; i<k; i++)
                nums[i] = -nums[i];
        }else if(k > zero_lower_bound){
            for(int i=0; i<zero_lower_bound; i++) // 将全部负数变为整数之后
                nums[i] = -nums[i];
            k = k-(zero_lower_bound+1-1); // 剩余翻转次数
            if(k%2 == 0) // 剩余为偶数，正反抵消
                ; 
            else{ // 剩余为奇数，用一次翻转当前最小的元素
                if(zero_lower_bound == 0) // 原来的元素全为整数，翻转第一个元素
                    nums[0] = -nums[0];
                else if(zero_lower_bound == nums.size()) // 原来的元素全为负数，翻转最后一个元素
                    nums[zero_lower_bound -1] = -nums[zero_lower_bound-1];
                else{ // 原来正负交替，翻转zero_lower_bound-1 or zero_lower_bound位置元素
                    int min_i;
                    if(nums[zero_lower_bound-1] < nums[zero_lower_bound])
                        min_i = zero_lower_bound-1;
                    else 
                        min_i = zero_lower_bound;
                    nums[min_i] = -nums[min_i];
                }
            }
        }

        // 累加求和
        int result = 0;
        for(int num : nums)
            result += num;
        return result;
    }
};