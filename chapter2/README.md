## 线性表

### 相关概念

严蔚敏《数据结构》、 [线性表详解：数据结构线性表10分钟入门](http://data.biancheng.net/linear_list/)

### Exercise 2.1 [线性表的合并](https://github.com/da1234cao/data_structure/blob/master/chapter2/2_1.cpp)

### Exercise [2.2合并两个有序表](https://github.com/da1234cao/data_structure/blob/master/chapter2/2_2.cpp)

### Exersier 2_22 和2_23 ，[一元多项式的相加](https://github.com/da1234cao/data_structure/blob/master/chapter2/2_22.cpp)和[一元多项式相乘](https://github.com/da1234cao/data_structure/blob/master/chapter2/2_23.cpp)。

我在C++的基础上，采用了两种思路。第二种更简单一点。

* 思路一

  用pair来存储系数和指数。pair存放在list中。整体的数据结构 `list< pair<int,int> >`  。

  `list`在数据结构中是双向链表。（书上思路）

* 思路二

  用map来存储。map<指数,系数>；可自动进行排序。

