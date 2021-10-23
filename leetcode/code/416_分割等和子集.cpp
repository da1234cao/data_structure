#include <vector>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int num : nums)
            sum += num;
        if(sum % 2 == 1)
            return false;
        int bag_weight = sum/2;

        // 是否能从nums中取出重量等于bag_weight

        //当dp[i][j],表示[0,i-1]个物品中，尽可能向weight容量的背包中，放入
        
        vector<vector<int>> dp(nums.size(),vector<int>(bag_weight+1,0));
        // 第一列初始化：dp[x][0]==0，表示背包为零，放入值为零
        // 第一行初始化：因为当无法放入的时候，需要继承上一行的值，所以，我们需要初始化第一行
        for(int i=nums[0]; i<bag_weight; i++)
            dp[0][i] = nums[0];

        for(int i=1; i<nums.size(); i++){ // 遍历物品
            for(int j=1; j<=bag_weight; j++){ //遍历背包容量
                if(nums[i] > j)
                    dp[i][j] = dp[i-1][j]; // 无法放入
                else
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j-nums[i]]+nums[i]); // 可以放入的时候后，判断是否放入
            }
        }

        if(dp[nums.size()-1][bag_weight] == bag_weight)
            return true;
        return false;
    }
};