#include <iostream>
#include <variant>

int main( int argc, char **argv )
{
    {
        std::variant<double, bool, std::string> var;
        var = "haha";
        
        struct {
          void operator()(double) { std::cout << "double!\n"; }
          void operator()(int) { std::cout << "int!\n"; }
          void operator()(std::string const&) { std::cout << "string!\n"; }
        } visitor;
        
        std::visit(visitor, var);
    }

    return 0;
}
