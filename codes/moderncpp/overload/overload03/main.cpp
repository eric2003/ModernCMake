#include <iostream>
#include <variant>

template <class F1, class F2>
struct overload : F1, F2
{
    overload(F1 const& f1, F2 const& f2) : F1{f1}, F2{f2} 
    {
        std::cout << "overload::overload\n";
    }
    ~overload()
    {
        std::cout << "overload::~overload\n";
    }
    
    //using F1::operator();
    //using F2::operator();
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

    return 0;
}
