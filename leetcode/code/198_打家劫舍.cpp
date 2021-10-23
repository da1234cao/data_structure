#include <vector>

using namespace std;


class Solution {
public:
    int rob(vector<int>& nums) {
        // 递推公式:dp[i] = max(dp[i-1],dp[i-2]+nums[i])

        // 题目限定，至少有一个元素
        if(nums.size() <= 2){
            if(nums.size() == 1)
                return nums[0];
            else if(nums.size() == 2)
                return max(nums[0], nums[1]);
            return 0;
        }

        //dp[i]表示[0,i]闭区间，能获得的最大财富
        vector<int> dp(nums.size(),0);
        dp[0] = nums[0];
        dp[1] = max(nums[0],nums[1]);

        for(int i=2; i<nums.size(); i++)
            dp[i] = max(dp[i-1],dp[i-2]+nums[i]);
        
        return dp[nums.size()-1];
    }
};