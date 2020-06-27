#include "matetemplate.h"
#include "mateplate_if.h"
#include "template_nonmeber.h"

#include <iostream>
#include <chrono>
#include <vector>
#include <list>
#include <cassert>
using namespace std;

void mate_template_test()
{
    auto start_t = chrono::system_clock::now();
    int result = Fibonacci<45>::value;
    auto end_t = chrono::system_clock::now();

    std::cout << "Fibonacci(100) = " << result << "\t" 
        << "elapsed time: " << (chrono::duration_cast<chrono::milliseconds>(end_t - start_t)).count() 
        << "s" << std::endl;

    start_t = chrono::system_clock::now();
    result = fibonacci(45);
    end_t = chrono::system_clock::now();
    std::cout << "Fibonacci(100) = " << result << "\t" 
    << "elapsed time: " << (chrono::duration_cast<chrono::milliseconds>(end_t - start_t)).count() 
    << "s" << std::endl;
}

void mt_ifelse()
{
    cout << "mate template if else test start ..." << endl;
    vector<int> v{1,2,3,4,5};
    vector<int>::iterator vite = v.begin();
    Test::advance(vite, 3);
    cout << *vite << endl;
    assert(*vite == 4);
    Test::advance(vite, -3);
    assert(*vite == 1);    
    cout << "--------------------." << endl;
    list<int> l{2,3,4,5,6};
    list<int>::iterator lite = l.begin();
    Test::advance(lite, 3);
    assert(*lite == 5);
    Test::advance(lite, -3);
    assert(*lite == 2);

    cout << "mate template if else test passed ..." << endl;
}

void nonmember_test()
{
    Rational<int> a(5, 1);
    Rational<int> b(6, 1);
    // operator*<>
    Rational<int> result2 = a * b;
    // Rational<int> result = 2  * a;//编译通过，但是没有operator*的定义，因此链接错误
}

int main(int argc, const char* argv[])
{
    nonmember_test();
    // mt_ifelse();
    // mate_template_test();
    
    return 0;
}