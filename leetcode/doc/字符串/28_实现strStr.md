## 前言

题目：[28. 实现 strStr()](https://leetcode-cn.com/problems/implement-strstr/)

参考答案：[实现 strStr()-力扣官方题解](https://leetcode-cn.com/problems/implement-strstr/solution/shi-xian-strstr-by-leetcode-solution-ds6y/)

---

## 提交代码

字符串匹配问题，如果不使用KMP算法，且允许调用库函数(不自己写暴力查找过程)，很容易实现。
```c++
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty())
            return 0;
        string::size_type result = haystack.find(needle); // 找到的子串的首字符位置，或若找不到这种子串则为 npos 。
        if(result == string::npos)
            return -1;
        else
            return int(result);
    }
};
```

关于字符串匹配算法原理参考：[字符串匹配的KMP算法-阮一峰](https://www.ruanyifeng.com/blog/2013/05/Knuth%E2%80%93Morris%E2%80%93Pratt_algorithm.html)、[字符串匹配的Boyer-Moore算法-阮一峰](https://www.ruanyifeng.com/blog/2013/05/boyer-moore_string_search_algorithm.html)。

PS：关于算法的代码实现。我看了半天，没看明白前缀子串数组是如何DP计算的。