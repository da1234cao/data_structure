#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // dp[i]表示i之前包括i的最长上升子序列的长度。

        vector<int> dp(nums.size(),1);

        for(int i=1; i<nums.size(); i++){
            for(int j=0; j<i; j++){
                if(nums[i]>nums[j])
                    dp[i] = max(dp[i],dp[j]+1); // i位置被选中时，[0,i]的最长公共子序列
            }
        }
        
        int len = 0;
        for(int i=0; i<dp.size(); i++)
            len = max(len,dp[i]);
        
        return len;
    }
};


int main(void){
    vector<int> nums = {10,9,2,5,3,7,101,18};
    Solution s;
    cout<<s.lengthOfLIS(nums)<<endl;
}