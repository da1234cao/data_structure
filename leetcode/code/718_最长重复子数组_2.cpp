#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        // 动态规划
        // 如果nums1[i]和nums2[j]位置的元素相同dp[i][j] = dp[i-1][j-1] + 1; 前一个位置相同，将dp[i-1][j-1]累加过来；前一个位置不相同，dp[i-1][j-1]位零
        
        int result = 0;
        vector<vector<int>> dp(nums1.size()+1,vector<int>(nums2.size()+1,0));

        for(int i=1; i<=nums1.size(); i++){
            for(int j=1; j<=nums2.size(); j++){
                if(nums1[i-1] == nums2[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                result = max(result,dp[i][j]);
            }   
        }

        return result;
    }
};