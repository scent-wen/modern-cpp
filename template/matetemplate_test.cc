#include "matetemplate_test.h"

#include <iostream>
#include <chrono>

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

int main(int argc, const char* argv[])
{
    mate_template_test();
    
    return 0;
}