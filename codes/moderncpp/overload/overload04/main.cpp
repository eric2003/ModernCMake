#include <iostream>
#include <variant>

template <class ...Fs>
struct overload : Fs... 
{
    overload(Fs const&... fs) : Fs{fs}...
    {
        std::cout << "overload::overload\n";
        std::cout << "sizeof...(Fs) = " <<  sizeof...(Fs) << std::endl;
        std::cout << "sizeof...(fs) = " <<  sizeof...(fs) << std::endl;
    }
    ~overload()
    {
        std::cout << "overload::~overload\n";
    }

    using Fs::operator()...;
};

int main( int argc, char **argv )
{
    {
        std::variant<std::string, int> var;
        var = 1;
        std::visit(
          overload(
            [](int){std::cout << "int!\n";}, 
            [](std::string const&){std::cout << "string!\n";}
          ),
          var
        );
    }
    {
        std::variant<std::string, int> var;
        var = 1;
        std::visit(
          overload(
            [](int){std::cout << "int!\n";}, 
            [](float){std::cout << "float!\n";}, 
            [](double){std::cout << "float!\n";}, 
            [](std::string const&){std::cout << "string!\n";}
          ),
          var
        );
    }

    return 0;
}
