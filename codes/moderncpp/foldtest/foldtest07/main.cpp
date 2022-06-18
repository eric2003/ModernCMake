#include <iostream>
#include <map>

template <typename... Args> bool plot()
{
    std::cout << "plot() number of Args = " << sizeof ... (Args) << std::endl;
    return true;
}

bool plot()
{
    std::cout << "my plot()" <<std::endl;
    return true;
}

template <typename A, typename B>
bool plot_basic(const A &a, const B &b, const std::string &format,
          const std::map<std::string, std::string> &keywords)
{
    std::cout << "plot_basic format = " << format << std::endl;
    return true;
}


template <typename A, typename B>
bool plot(const A &a, const B &b)
{
    std::cout << "plot 0000 " << std::endl;
    plot_basic( a, b, "", {} );
    return true;
}

template <typename A, typename B, typename... Args>
bool plot(const A &a, const B &b, const std::string &format, Args... args)
{
    std::cout << "plot 1111 number of args = " << sizeof ... (args) << std::endl;
    plot_basic( a, b, format, {} ) && plot( args... );
    return true;
}

template <typename A, typename B, typename... Args>
bool plot(const A &a, const B &b, const std::map<std::string, std::string> &keywords, Args... args)
{
    std::cout << "plot 2222 number of args = " << sizeof ... (args) << std::endl;
    plot_basic(a, b, "", keywords ) && plot( args... );
    return true;
}

template <typename A, typename B, typename... Args>
bool plot(const A &a, const B &b, const std::string &format, const std::map<std::string, std::string> &keywords, Args... args)
{
    std::cout << "plot 3333 number of args = " << sizeof ... (args) << std::endl;
    plot_basic(a, b, format, keywords ) && plot( args... );
    return true;
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
    plot( i, j, keywords );
    //plot( i, j, j, k, keywords );
    plot( i, j, "haha", keywords, i, j, "hello", keywords );
    return 0;
}
