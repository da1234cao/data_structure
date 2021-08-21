#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        /// 我调试了下代码。可以看到这种查找方式是，从后向前，每四个一组，顺序查找。适用于无序情况。
        vector<int>::iterator it = find(nums.begin(),nums.end(),target);
        if(it != nums.end())
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