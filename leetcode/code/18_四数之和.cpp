#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        const int len = nums.size();

        if(len < 4) // 长度小于4，直接返回
            return result;
        
        sort(nums.begin(),nums.end());

        for(int i=0; i<len; i++){
            // 不可以这样，因为几个负数，可以凑成更小的负数
            // if(nums[i] > target) // 如果四个数中最小一个都大于target，则跳出循环
            //     break;
            if(i>0 && nums[i]==nums[i-1]) // i不能取之前取过的数
                continue;
            
            for(int j=i+1; j<len; j++){
                if(j>i+1 && nums[j]==nums[j-1]) // i确定之后，j不能取之前取过的数
                    continue;
                int left = j+1;
                int right = len-1;
                int needNum = target-nums[i]-nums[j];
                while(left < right){ // i,j确定之后，在[left,right]闭区间中寻找，四者和为target的组合
                    if(nums[left]+nums[right] == needNum){
                        result.push_back({nums[i],nums[j],nums[left],nums[right]});
                        left++;
                        right--; // 前往下一个位置
                        while(left < right && nums[left] == nums[left-1]) left++; // i,j确定之后，left不能取之前取过的内容
                        while(left < right && nums[right] == nums[right+1]) right--; // i,j确定之后，right不能取之前取过的内容
                    }else if(nums[left]+nums[right] > needNum)
                        right--;
                    else
                        left++;
                }
            }
        }

        return result;
    }
};

int main(void){
    vector<int> nums = {1,0,-1,0,-2,2}; int target = 0;
    Solution s;
    s.fourSum(nums,target);
}