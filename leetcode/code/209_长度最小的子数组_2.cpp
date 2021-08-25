#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
private:
    int sum(int start, int end, vector<int>& nums){
        // 计算[start,end]范围元素的和
        // 这个函数可以用前缀和函数进行优化。创建prefixSum为私有成员变量。
        return accumulate(nums.begin()+start,nums.begin()+end,nums[end]);
    }
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i=0,j=0;
        const int len = nums.size();
        int minLen = len+1;
        for(; j<len; ){ 
            if(i==j && nums[i]>=target) // 任何时候，慢指针i，不允许，在快指针j，前面；当相等的时候，说明范围内只有一个元素;如果这个元素大于target，直接返回1
                return 1;
            if(sum(i,j,nums) < target)
                j++; // 扩大范围
            else{
                minLen = minLen < j-i+1 ? minLen:j-i+1;
                i++;// 缩放范围：这里每次只所以一步；可以优化这里一次缩小多步
            }
        }
        return minLen > len ? 0:minLen;
    }
};

int  main(void){
    int target = 6;
    vector<int> nums ={10,2,3};
    Solution s;
    cout<<s.minSubArrayLen(target,nums)<<endl;
    return 0;
}