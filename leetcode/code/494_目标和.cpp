#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        /**
         * 思路：1.先将所有的值转换成正整数。
         *      2.求和，用和减去target。
         *      3.剩余值如果正好可以分两半，则满足要求
         *      4.步骤3可以通过01背包问题实现。其中，背包大小为剩余值的一半
         *      5.可能出现多次满足要求的情况，每次出现都记录下
         * */ 

        /**
         * 该思路错误。反例：[2,1,3,5,2,1,4,5,8,3,1,4]， target=3
         * 输出6； 预期结果为238
        */

        // 全部转换成正整数，并求和
        int sum = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]<0)
                nums[i] = -nums[i];
            sum += nums[i];
        }

        // 背包大小
        if(sum-target == 0){ //全部数字用于抵消target:
            int result = 0;
            for(auto num : nums)
                num == 0 ? result++:result;
            return result == 0 ? 1:result*2;
        }
        if((sum-target)%2 != 0)
            return 0;
        int bag_weight = (sum-target)/2;

        int result = 0;
        vector<int> dp(bag_weight+1,0);
        for(int i=0; i<nums.size(); i++){ // 遍历物品
            for(int j=bag_weight; j>=nums[i]; j--){ // 遍历背包
                // dp[j] = max(dp[j],dp[j-nums[i]]+nums[i]);
                if(dp[j-nums[i]]+nums[i] >= dp[j]){ // 放这件物品
                    dp[j] = dp[j-nums[i]]+nums[i];
                    if(dp[j]==bag_weight) // 遇到一种满足要求哒
                        result++;
                }
            }
            // for(int i=0; i<=bag_weight; i++)
            //     cout<<dp[i]<<" ";
            // cout<<endl;
        }

        return result;
    }
};

int main(void){
    vector<int> nums = {1,0,0};
    int target = 1;
    Solution s;
    cout<<s.findTargetSumWays(nums,target);
}