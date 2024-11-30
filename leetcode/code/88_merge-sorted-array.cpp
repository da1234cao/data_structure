// https://leetcode.cn/problems/merge-sorted-array/?envType=study-plan-v2&envId=top-interview-150

#include <cassert>
#include <iostream>
#include <limits>
#include <random>
#include <vector>

using namespace std;

class Solution {
public:
  void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
    assert(nums1.size() == m + n);

    if (m == 0 && n == 0) {
      return;
    }

    if (m == 0 && n != 0) {
      for (int i = 0; i < n; i++) {
        nums1[i] = nums2[i];
      }
      return;
    }

    if (m != 0 && n == 0) {
      return;
    }

    // 先将nums1中的元素，整体后移n个位置
    for (int i = m - 1, j = m + n - 1; i >= 0; i--, j--) {
      nums1[j] = nums1[i];
      //   nums1[i] = 0;
    }

    // 合并两个非递减顺序数组
    int i = n, j = 0, k = 0;
    for (; i < m + n && j < n; k++) {
      if (nums1[i] < nums2[j]) {
        nums1[k] = nums1[i];
        // nums1[i] = 0;
        i++;
      } else {
        nums1[k] = nums2[j];
        // nums2[j] = 0;
        j++;
      }
    }

    // 剩余的部分整体拷贝
    while (j < n) {
      nums1[k++] = nums2[j++];
    }
  }
};

int main(int argc, char *argv[]) {
  int m = 1;
  std::vector<int> nums1 = {4, 0, 0, 0, 0, 0};
  int n = 5;
  std::vector<int> nums2 = {1, 2, 3, 5, 6};

  class Solution s;
  s.merge(nums1, m, nums2, n);
}