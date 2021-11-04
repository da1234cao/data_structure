#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // 统计每个数字，它前面比它小的个数+1
        // 返回统计中的最大值

        vector<int> dp(nums.size(),0);
        dp[0] = 1;

        for(int i=1; i<nums.size(); i++){
            int j = i-1;
            while(j>=0 && nums[j]>=nums[i]) // 这里是有问题的。它遇到第一个小于它的数字便停止
                j--;
            if(j==-1)
                dp[i] = 1;
            else
                dp[i] = dp[j] + 1;
        }

        int len = 0;
        for(int i=0; i<dp.size(); i++)
            len = max(len,dp[i]);
        
        return len;
    }
};


int main(void){
    vector<int> nums = {0,1,0,3,2,3};
    Solution s;
    cout<<s.lengthOfLIS(nums)<<endl;
}