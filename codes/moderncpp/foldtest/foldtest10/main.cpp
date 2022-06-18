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
    std::cout << "plot 0000  " << std::endl;
    plot_basic( a, b, "", std::map<std::string, std::string>{} );
    return true;
}

template <typename A, typename B>
bool plot(const A &a, const B &b, const std::string &format)
{
    std::cout << "plot 1111 " << std::endl;
    plot_basic( a, b, format, std::map<std::string, std::string>{} );
    return true;
}

template <typename A, typename B>
bool plot(const A &a, const B &b, const std::map<std::string, std::string> &keywords)
{
    std::cout << "plot 2222 " << std::endl;
    plot_basic(a, b, "", keywords );
    return true;
}

template <typename A, typename B, typename... Args>
bool plot(const A &a, const B &b, const std::string &format, Args... args)
{
    std::cout << "plot 3333 number of args = " << sizeof ... (args) << std::endl;
    plot(a, b, format ) && plot( args... );
    return true;
}

int main( int argc, char **argv )
{
    int i = 0;
    int j = 1;
    int k = 1;
    std::map<std::string, std::string> keywords;
    plot( i, j, "cfd" );
    plot( i, j, keywords );
    plot( i, j );
    plot( i, j, "cfd", i, j, "OneFLOW" );
    return 0;
}
