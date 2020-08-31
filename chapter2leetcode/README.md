# 数组
数组的虚拟地址空间连续，也即线性表，非链表。

我按照leetcode数组tag中题目出现的先后顺序刷题，逢山劈山，遇水架桥。

刷够二十题，暂时停手，去下一关。

---

1. [两数之和](https://leetcode-cn.com/problems/two-sum/)

   参考文章：[C++ vector 容器浅析](https://www.runoob.com/w3cnote/cpp-vector-container-analysis.html) 、[vector 的六种 创建和初始化方法](https://blog.csdn.net/veghlreywg/article/details/80400382)

   对初代代码进行优化：[leetcode-两数之和-C++](https://blog.csdn.net/cat1992/article/details/80372617#commentBox)
   
   #2020-6-21

2. [寻找两个正序数组的中位数](https://leetcode-cn.com/problems/median-of-two-sorted-arrays/)

   参考文章：[中位数](https://zh.wikipedia.org/wiki/%E4%B8%AD%E4%BD%8D%E6%95%B8)

   #2020-7-7

3. [盛最多水的容器](https://leetcode-cn.com/problems/container-with-most-water/)

   这道题目的暴力解，比较简单，计算出两两之间的面积就好。

   使用双指针的证明，官网给出了类似于反证的方法（感觉这证明过程怪怪的～）。

   * 两指针之间可能存在更大的面积，遍历完才能知道，所以得移动左指针或者右指针。
   * 假设左指针对应的高度较低。如果此时移动右指针，必然面积不是最大。
   * 所以只好移动左指针，即较低的指针。
   * 重复上述过程，直至遍历结束。

   #2020-7-14

4. [三数之和](https://leetcode-cn.com/problems/3sum/)

   两数之和，采用排序+双指针的方法。（当然两数之和也可以采用hash的方法）

   两数之和的基础上，求三数之和就好。
   
   #2020-7-15