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
    {
        std::variant<int, std::string> var;
        //var = "haha";
        var = 1;
        
        std::visit(
            []( auto&& value ) {
              if constexpr( std::is_same_v<decltype(value), std::string&> )
              {
                  std::cout << "a string of length " << value.length() << '\n';
              }
              else if constexpr( std::is_same_v<decltype(value), int&> )
              {
                  std::cout << "an int& \n";
              }
              else
              {
                  std::cout << "others \n";
              }
            },
            var
          );
    }

    return 0;
}
