#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        int zero_cnt=0;
        for(auto num : nums){
            sum += num;
            if(num==0)
                zero_cnt++;
        }
        target = abs(target);
        if(sum-target<0 || (sum-target)%2!=0) // 所有的装入都不够；或者扣除装入之后，剩余的不能均分
            return 0;
        // int bag_weight = (sum - target)/2;
        int bag_weight = (sum + target)/2;

        // dp[i][j]表示，在[0,i]物品中，装满j容量的方法数目
        // 初始化行：dp[0][nums[0]] = 1;第一个物品恰好装满
        // 初始化列：dp[x][0]=1; 此时背包容量为零，表示所有物品全部需要(sum==target)，所以只有一种方法
        vector<vector<int>> dp(nums.size(),vector<int>(bag_weight+1,0));
        dp[0][nums[0]] = 1;
        for(int i=0; i<nums.size(); i++)
            dp[i][0] = 1;

        for(int i=1; i<nums.size(); i++){ // 遍历物品
            for(int j=1; j<=bag_weight; j++){ // 遍历背包
                if(j<nums[i])
                    dp[i][j] = dp[i-1][j]; // 装不下，只好继承，使用前i-1件装满j容量；
                else{
                    if(nums[i]!=0)
                        dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i]]; // 不装当前元素，使用前i-1件装满j容量 +  使用当前元素，使用前i件装满j容量 
                    else{
                        dp[i][j] = dp[i-1][j]; // 如果是0，我们当没看见这个元素
                    }
                }
            }
        }

        for(auto vec : dp){
            for(auto v : vec)
                cout<<v<<" ";
            cout<<endl;
        }

        return dp[nums.size()-1][bag_weight]*(1<<zero_cnt); // 0的正负都不影响结果，正负均可
    }
};

int main(void){
    vector<int> nums = {0,0,0,0,0,0,0,0,1};
    int target = 1;

    // vector<int> nums = {1,0,0};
    // int target = 1;

    Solution s;
    cout<<s.findTargetSumWays(nums,target);
}