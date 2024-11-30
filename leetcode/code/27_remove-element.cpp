// https://leetcode.cn/problems/remove-element/description/?envType=study-plan-v2&envId=top-interview-150

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  int removeElement(vector<int> &nums, int val) {
    if (nums.size() == 0) {
      return 0;
    }

    if (nums.size() == 1) {
      return nums[0] == val ? 0 : 1;
    }

    int i = 0, j = nums.size() - 1;
    for (; i < j;) {
      // 确保j的位置,可以放入val(位置在最后且不是val的位置)
      while (nums[j] == val && j > i) {
        j--;
      }

      // 位置最前面且时val的位置
      while (nums[i] != val && i < j) {
        i++;
      }

      if (i != j) {
        std::swap(nums[i], nums[j]);
      }
    }
    return nums[i] == val ? i : i + 1;
  }
};