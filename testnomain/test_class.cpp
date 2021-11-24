#include "test_class.h"

testclass::testclass()
{
    std::cout << "构造函数执行" << std::endl;
}

int testclass::Geter()
{
    std::cout << "Geter()执行" << std::endl;
    return value;
}

void testclass::Setter(int i)
{
    std::cout << "Setter(int i)执行" << std::endl;
    value = i;
}