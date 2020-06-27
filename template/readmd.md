## 元编程

- ### 元编程之中的循环

  - 元循环使用编译之中的递归来完成它的循环，当然递归需要一个递归终止条件作为递归出口，这里使用**全特化**来实现递归终止。用法查看tempalte.h文件

- ### 元编程之中的**if...else**语

  - 元编程之中使用override来完成if...else 判断，也就是在编译期变决定调用哪个函数了。本例使用traits这个技术来说明元编程之中的判断，type traits 技术也同样很重要。详情查看matetempalte_if.h文件。
  - 这里说明一下，为什么使用typeid来根据类型进行调用，其一是效率的问题。对于不同的类型，编译器会编译所有源代码，因此虽然typeid判断不成功，但是源代码依旧会编译，便会出现问题。

- 模板类继承出现的问题

  - 从模板类派生出来的类的member-function，它在调用函数的时候，并不会进入base的作用域查找，因为，编译器知道，模板base在特化之后可能没有实现这个函数。
  - 这里有一些小技巧来使base的方法有效
    - 使用this->
    - using Base<T>::basefunction;
    - 直接调用，Base<T>::basefunction(); <font color=#ff00ff>这个方法往往最差劲，因为这个方法对于virtual关键字失效</font>

- 将与参数无关的代码抽离template，使用这种技巧来解决或者注意代码膨胀的问题

  - 主要是讨论非类型参数所带来的膨胀，非类型参数如下所示：

    ```c++
    template<typename T, size_t N>
    class SquareMatrix{
    public:
       ...
       void invert();
    }
    //非类型模板参数通常用来指定默认值
    template<typename T, int MAXSIZE = 20>
    class Stack
    {
        ...
    }
    
    //非类型函数模板参数
    template<typename T, int VAL>
    T addValue(const T& x)
    {
        return x + VAL;
    }
    //高级用法，我们可以使用类型参数定义非类型参数的type
    template<typename T, T VAL>
    T addValue(const T& x)
    {
        return x+VAL;
    }
    //强大作用，这里其实有点std::bind的作用，只是std::bind实在运行时候构造，而现在这个传入的仿函数在编译的时候已经决定了。这也决定了其灵活性底。
    #include <algorithm>
    std::vector<int> ivec;
    std::transform(src.begin(), src.end(),      // 原容器（待转换）的起点和终点 
                        dst.begin(),            // 目标容器的起点
                        addValue<std::vector<int>::value_type, 10>);    // 操作或者函数（也可以是仿函数）
    ```

  - 非类型模板参数的限制:一般而言，**它可以是常整数（包括enum枚举类型）或者指向外部链接对象的指针**。浮点数和类对象（class-type）不允许作为非类型模板参数：

  - 

- 

  

## 遇到的问题：

1. size_t无法在头文件之中使用？但是该程序可以在远程主机上使用
   
   1. 答案：size_t定义在stddef.h文件之中，以前使用的时候没有暴露出来的原因就是，在包含一些容器，像是vector,list的时候，已经包含进该头文件了，因此该问题便不会出现。解决方法就是:
   
      #include <cstddef>
   
   2. 
   
2. 



