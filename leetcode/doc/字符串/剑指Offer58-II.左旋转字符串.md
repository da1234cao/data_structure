## 题目

[剑指 Offer 58 - II. 左旋转字符串](https://leetcode-cn.com/problems/zuo-xuan-zhuan-zi-fu-chuan-lcof/)

---

## 提交代码

思路：字符串的切片与拼接。

```c++
class Solution {
public:
    string reverseLeftWords(string s, int n) {
        int s1Len = n;
        int s2Len = s.size()-n;

        string s1 = s.substr(0,s1Len);
        string s2 = s.substr(s1Len,s2Len);

        return s2+s1;
    }
};
```