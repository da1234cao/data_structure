#include <vector>

using namespace std;

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        vector<int> dp(nums.size(),1);

        for(int i=1; i<nums.size(); i++){
            if(nums[i]>nums[i-1])
                dp[i] = dp[i-1]+1;
        }

        int len = 0;
        for(int i=0; i<dp.size(); i++)
            len = max(len,dp[i]);
        
        return len;
    }
};