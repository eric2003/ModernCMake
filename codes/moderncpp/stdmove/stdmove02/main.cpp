#include <iomanip>
#include <iostream>
#include <utility>
#include <vector>
#include <string>
 
int main()
{
    std::string str = "str";
    std::string str1 = std::move(str);
    std::string str2 = "haha";
    std::string str3 = "hello";
    std::cout << "str is " << std::quoted(str) << '\n';
    std::cout << "str1 is " << std::quoted(str1) << '\n';
    std::cout << "str2 is " << std::quoted(str2) << '\n';
    std::cout << "str3 is " << std::quoted(str3) << '\n';
    str3 = std::move( str2 );
    std::cout << "str2 is " << std::quoted(str2) << '\n';
    std::cout << "str3 is " << std::quoted(str3) << '\n';
    return 0;
}