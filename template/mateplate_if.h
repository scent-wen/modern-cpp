/**
 *  使用一个迭代器advance 函数作为示例。 
 * 
 */
#pragma once
#include <cstddef>
#include <iterator>
#include <stdexcept>
#include <iostream>

namespace Test{
template<typename IterT>
void doAdvance(IterT& iter, int n, std::random_access_iterator_tag)
{
    std::cout << "using random iterator advance function" << std::endl;
    iter += n;
}

template<typename IterT>
void doAdvance(IterT& iter, int n, std::bidirectional_iterator_tag)
{
    std::cout << "using bidirectional iterator advance function" << std::endl;
    if(n >= 0)
    {
        while(n--)
            ++iter;
    }
    else
    {
        while(n++)
            --iter;
    }
}

template<typename IterT>
void doAdvance(IterT& iter, int n, std::forward_iterator_tag)
{
    if(n >= 0)
    {
        while(n--)
            ++iter;
    }
    else
    {
        throw std::invalid_argument("forward_iterator_tag cannot to backward");
    }
}

template<typename IterT>
void advance(IterT& iter, int n)
{
    // typename std::iterator_traits<iter>::value_type i_type;
    doAdvance(iter, n, typename std::iterator_traits<IterT>::iterator_category());

    //这里不使用type_id技术，也就是下边的代码
    /*
    if(typeid(typename std::iterator_traits<IterT>::iterator_category) == 
        typeid(std::random_access_iterator_tag))
        {
            //...调用代码
            iter += n; //编译期间，如果if不成立，但是这里的源代码还是会编译，但是传进来的ite不支持这样的运算，便会出现运算错误。
        }
    */
}
}