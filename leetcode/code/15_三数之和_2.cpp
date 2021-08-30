#include <unordered_map>
#include <unordered_set>
#include <set>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        const int len = nums.size();

        if(len < 3){ // 不足三个元素，直接返回
            return result;
        }

        sort(nums.begin(),nums.end()); // 升序排序，便于去重和求和

        for(int i=0; i<len; i++){
            if(nums[i]>0) // 三个数中第一个数大于零，则不存在
                break;
            
            if(i>0 && nums[i]==nums[i-1]) // 如果组合中的第一个数之前取过，去重不取
                continue;
            
            int left = i+1; 
            int right = len-1;
            int needNum = -nums[i];
            while(left < right){  // [left,right]闭区间中有不同的解，较大+较小，偏大+偏小
                if(nums[left]+nums[right] == needNum){
                    result.push_back({nums[i],nums[left],nums[right]});
                    left++;
                    right--; // 分别前往下一个位置
                    while(left < right && nums[left] == nums[left-1]) left++; // 下一个要取的数，之前的不能取过
                    while(left < right && nums[right] == nums[right+1]) right--; // 下一个要取的数，之前的不能取过
                }else if(nums[left]+nums[right] > needNum)
                    right--;
                else
                    left++;
            }
        }

        return result;
    }
};

int main(void){
    vector<int> nums={-1,0,1,2,-1,-4};
    Solution s;
    s.threeSum(nums);
}