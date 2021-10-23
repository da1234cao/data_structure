#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        // 思路：完全背包中的排列问题
        // 先遍历背包，再遍历物品。(6-1=5;6-5=1)

        // dp[j]：背包容量为j时，组合数
        vector<int> dp(target+1,0);
        dp[0] = 1; // 初始化，表示仅使用某一个物品，可以装满
        for(int j=0; j<=target; j++){ // 先遍历背包
            for(int i=0; i<nums.size(); i++){ // 后遍历物品
                if(j>=nums[i]){
                // if (j>=nums[i] && dp[j] < INT_MAX - dp[j - nums[i]]) { // 这题目怕不是智障？题目已经限定结果不会溢出；但是通过丢弃正确解来避免溢出，也是绝了
                    dp[j] += dp[j-nums[i]]; // 当背包容量为j时候=前面dp[j-nums[i]]的组合+物品i
                }
            }
        }

        return dp[target];
    }
};