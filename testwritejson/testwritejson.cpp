#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <iostream>
#include <boost/algorithm/string.hpp>
#include <boost/test/unit_test.hpp>
int main()
{
    boost::property_tree::ptree ptValItem1, ptValItem2, ptValItem3, ptVals,root;
    ptValItem1.put(std::string("listkey1"), std::string("8859555listvalue1"));
    ptValItem1.put(std::string("listkey2"), std::string("8859555"));
    ptValItem1.put(std::string("listkey3"), std::string("listvalue3"));
    root.add_child(std::string("list"), ptValItem1);


    std::stringstream ss;
    boost::property_tree::write_json(ss, root);
    std::string strContent = ss.str();
    ss.str();

    std::cout << strContent << "--------------------------------------\n";


    boost::property_tree::ptree s1 = root.get_child("list");
    std::string s2 = s1.get<std::string>("listkey1");
    std::string s3 = root.get_child("list").get<std::string>("listkey1").c_str();
    auto fmt = boost::format("send,%1%") %s3;
    std::string s4 = fmt.str();
    std::cout << s2 << std::endl;
    std::cout << s3 << std::endl;
    std::cout << fmt << std::endl;
    std::cout << s4 << std::endl;
    std::cout << "--------------------------------------\n";
    std::string s5 = root.get_child("list").get<std::string>("listkey2").c_str();
    std::string s6;
    if(s5.length() > 0)
    {
        s6 = s3.substr(s5.length(),s3.length() - s5.length() + 1);
    }
    auto fmt2 = boost::format("send,%1%") %s6;
    s6 = fmt2.str();
    std::cout << fmt2 << std::endl;
    std::cout << s3 << std::endl;
    std::cout << s6 << std::endl;

    std::cout << "--------------------------------------\n";

    std::string s7 = boost::algorithm::erase_head_copy(s3, s5.length());
    if(boost::algorithm::istarts_with(s3,s5))
    {
        s3 =  boost::algorithm::erase_head_copy(s3, s5.length());
        std::cout << s5 << std::endl;
    }
    auto fmt3 = boost::format("%1%") %s3;
    s3 = fmt3.str();
    std::cout << fmt3 << std::endl;
    std::cout << s3 << std::endl;

    
    std::cout << "--------------------------------------\n";
    

}