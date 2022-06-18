#include <iostream>
#include <map>

template <typename... Args> bool plot()
{
    std::cout << "plot() number of Args = " << sizeof ... (Args) <<std::endl;
    return true;
}

bool plot()
{
    std::cout << "my plot()" <<std::endl;
    return true;
}

template <typename A, typename B>
bool plot(const A &a, const B &b, const std::string &format = "",
          const std::map<std::string, std::string> &keywords = {})
{
    std::cout << "plot 3 format = " << format << std::endl;
    return true;
}

template <typename A, typename B>
bool plot(const A &a, const B &b, const std::map<std::string, std::string> &keywords)
{
    std::cout << "plot 4 keywords.size() = " << keywords.size() << std::endl;
    return plot(a, b, "", keywords);
}

template <typename A, typename B, typename... Args>
bool plot(const A &a, const B &b, const std::string &format, const std::map<std::string, std::string> &keywords, Args... args)
{
    std::cout << "plot 5 number of args = " << sizeof ... (args) << std::endl;
    return plot(a, b, format,keywords) && plot(args...);
}

int main( int argc, char **argv )
{
    plot();
    plot<>();
    plot<int>();
    plot<int, float>();
    int i = 0;
    int j = 1;
    int k = 1;
    std::map<std::string, std::string> keywords;
    plot( i, j );
    plot( i, j, "haha" );
    plot( i, j, "haha", keywords );
    return 0;
}
