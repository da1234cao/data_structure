#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        /// std::binary_search:提供了二分查找，但是返回值是bool型
        /// std::lower_bound:返回范围内首个不小于target元素的迭代器。这个每次步长为一半，和二分查找时间复杂度相同。
        vector<int>::iterator it = lower_bound(nums.begin(),nums.end(),target);
        if((it != nums.end()) & (*it == target))
            return distance(nums.begin(),it);
        else
            return -1;
    }
};

int main(void) {
    vector<int> nums = {-1,0,3,5,9,12}; int target = 9;
    Solution s;
    int ans = s.search(nums,target);
    cout<<ans<<endl;
}