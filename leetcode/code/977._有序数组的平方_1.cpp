#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        // 暴力解，先平方，后排序；时间复杂度O(nlogn)
        for(auto &num : nums) 
            num*=num;
        sort(nums.begin(),nums.end());
        return nums;
    }
};

int main(void){
    vector<int> nums = {-7,-3,2,3,11};
    Solution s;
    s.sortedSquares(nums);
    for(auto tmp:nums)
        cout<<tmp<<" ";
}