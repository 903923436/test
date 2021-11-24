#include<iostream>

int main()
{
    uint64_t a = 5007899978798798798798798;
    uint64_t b = a <<48;
    int c = 999999999999999999999999999999999999999999999;
    char srt[8] = "9999999";
    std::cout << c << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << srt << std::endl;

    return 0;
}
