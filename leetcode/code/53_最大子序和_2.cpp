#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // 逻动态规划；dp[i]表示，包含i的，最大连续自序和
        vector<int> dp(nums.size(),0);
        dp[0] = nums[0];
        int result = dp[0];
        for(int i=1; i<nums.size(); i++){
            dp[i] = max(dp[i-1]+nums[i], nums[i]); // 判断是否从头再来
            result = max(result, dp[i]);
        }
        return result;
    }
};