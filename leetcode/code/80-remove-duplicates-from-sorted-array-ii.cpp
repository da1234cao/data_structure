#include <vector>

using namespace std;

class Solution {
public:
  int removeDuplicates(vector<int> &nums) {
    int same_value_bound = 2;
    if (nums.size() <= 2) {
      return nums.size();
    }

    int slow = 0, fast = 1;
    int same_value = nums[0];
    int same_value_cnt = 1;

    for (; fast < nums.size(); fast++) {
      if (nums[fast] == same_value) {
        same_value_cnt++;
        if (same_value_cnt > same_value_bound) {
          continue;
        } else {
          slow++;
          nums[slow] = nums[fast];
        }
      } else {
        same_value = nums[fast];
        same_value_cnt = 1;
        slow++;
        nums[slow] = nums[fast];
      }
    }

    return slow + 1;
  }
};