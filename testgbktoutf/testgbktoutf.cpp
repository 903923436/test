#include <iostream>
#include <boost/locale/conversion.hpp>
#include <boost/locale.hpp>
int main()
{
    boost::locale::conv::to_utf<char>(value,std::string);

    return 0;
}