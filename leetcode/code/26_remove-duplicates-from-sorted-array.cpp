
// https://leetcode.cn/problems/remove-duplicates-from-sorted-array/?envType=study-plan-v2&envId=top-interview-150

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  int removeDuplicates(vector<int> &nums) {
    const int size = nums.size();
    if (size == 0 || size == 1) {
      return size;
    }

    int slow = 0, fast = 0;
    for (; fast < size - 1;) {
      if (nums[fast] != nums[fast + 1]) {
        if (slow != fast) {
          nums[slow] = nums[fast];
        }
        slow++;
        fast++;
      } else {
        fast++;
        // [slow,fast) 范围内是可以覆盖的
      }
    }

    if (slow != fast) {
      nums[slow] = nums[fast];
      slow++;
    } else {
      slow++;
    }
    return slow;
  }
};
