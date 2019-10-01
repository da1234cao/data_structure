## chapter3 栈和队列

参考书籍 ：严蔚敏《数据结构》 《c++ primer》第五版

参考文章：[数据结构栈(Stack)和队列(Queue)详解](http://data.biancheng.net/stack_queue/)

### Exercise3.1  [数制转换](https://github.com/da1234cao/data_structure/blob/master/chapter3/3_1.cpp)

书上用，栈的思路来实现进制转换是很好的。

但是，函数在参数的输入和返回方面，不好。且只能处理十进制以内的转换。

因为，函数一旦要处理类似十六进制，会涉及到字符。稍微麻烦些。

上面链接中的函数，能实现**十六进制内，任意两进制之间的转换**。

注：链接中的**代码**可以简化。**可以使用`reverse(s)`来代替栈**。但为了体现栈的思想，代码中，我任用栈实现。

### Exercise 3.2 [行编辑器](https://github.com/da1234cao/data_structure/blob/master/chapter3/3_2.cpp)

### Exercise 3.3 [迷宫求解](https://github.com/da1234cao/data_structure/blob/master/chapter3/3_3.cpp)

### Exercise 3.4 [表达式求值](https://github.com/da1234cao/data_structure/blob/master/chapter3/3_4.cpp)

书上用栈来实现表达式求解的思路很好。类似的程序，可以参看《C语言程序设计》中逆波兰式的求解。

但是书上代码有三个地方需要完善：

* 如何用程序设计优先级的比较：要实现precede函数
* 如何计算：实现operate
* 最后一个尤为重要：如何实现**多位数**、**double、int不同类型**的计算。

我将**计算器**代码，封装成一个类，放在[3_4的头文件](https://github.com/da1234cao/data_structure/blob/master/chapter3/3_4.h)中。当由于目前，没有实际写过继承等代码，在封装上有什么不当之处，请指正。

### Exercise 3.5 [汉诺塔递归实现](https://github.com/da1234cao/data_structure/blob/master/chapter3/3_5.cpp)

