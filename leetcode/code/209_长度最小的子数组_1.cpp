#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        const int len = nums.size();
        // 计算前缀和
        vector<int> prefixSum(nums.size(),0);
        for(int i=1; i<len; i++)
            prefixSum[i] = prefixSum[i-1] + nums[i-1];
        prefixSum.push_back(prefixSum[len-1]+nums[len-1]); // 因为前缀和没法包含最后一个元素，这里修正下。所以前缀和比nums多一个元素

        // 时间复杂度为O((1+n)*n/2)=O(n^2)
        for(int step=1; step<=len; step++){
            for(int i=0; i+step<=len; i++){
                if(prefixSum[i+step]-prefixSum[i] >= target)
                    return step;
            }
        }

        return 0;
    }
};

int  main(void){
    int target = 7;
    vector<int> nums ={2,3,1,2,4,3};
    Solution s;
    cout<<s.minSubArrayLen(target,nums)<<endl;
    return 0;
}