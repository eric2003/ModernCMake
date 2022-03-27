#include <iostream>
#include <variant>
#include <functional>

template <class ...Fs>
struct Overload : Fs... 
{
    template <class ...Ts>
    Overload(Ts&& ...ts) : Fs{std::forward<Ts>(ts)}...
    {
        std::cout << "Overload::Overload\n";
        std::cout << "sizeof...(Ts) = " <<  sizeof...(Ts) << std::endl;
        std::cout << "sizeof...(ts) = " <<  sizeof...(ts) << std::endl;
    }
    ~Overload()
    {
        std::cout << "Overload::~Overload\n";
    }

    using Fs::operator()...;
};

int main( int argc, char **argv )
{
    {
        struct X{};
      
        auto f1 = std::function<void(int)>{ [](int){ std::cout << "int!\n";} };
        auto ux = std::make_unique<X>();
      
        std::variant<std::string, int> var;
        var = 1;
        std::visit(
          Overload(
            f1, //copied
            [ux = std::move(ux)](std::string const&){ std::cout << "std::string!\n"; } //move only
          ),
          var
        );
    }
 
    return 0;
}
