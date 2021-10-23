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
         *      5.背包问题，动态规划。其中，dp[j]表示，装满容量为j背包的方法有的dp[j]中。滚动数组中，dp[j] += dp[j-nums[i]]
         * */ 

        int sum = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]<0)
                nums[i] = -nums[i];
            sum += nums[i];
        }
        
        if( sum-abs(target)<0 || (sum-abs(target))%2 != 0)
            return 0;
        int bag_weight = (sum-abs(target))/2;

        vector<int> dp(bag_weight+1,0);
        dp[0] = 1; // 表，东西全部装入
        // dp[nums[0]]=1; // 在循环里面，会被正确赋值
        for(int i=0; i<nums.size(); i++){ // 遍历物品
            for(int j=bag_weight; j>=nums[i]; j--){ // 遍历背包
                    dp[j] += dp[j-nums[i]]; // 如果nums[i]为零，将自己翻倍。因为0的正负都不影响
                }
        }

        return dp[bag_weight];
    }
};

int main(void){
    vector<int> nums = {2,107,109,113,127,131,137,3,2,3,5,7,11,13,17,19,23,29,47,53};
    int target = 1000;
    Solution s;
    cout<<s.findTargetSumWays(nums,target);
}