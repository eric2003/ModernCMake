#include <iostream>

template<typename ... Ts>                                                 
struct Overload : Ts ... { 
    using Ts::operator() ...;
};
//template<class... Ts> Overload(Ts...) -> Overload<Ts...>;

int main( int argc, char **argv )
{
    auto TypeOfIntegral = Overload {     // (1)                                  
        [](char) { return "char"; },
        [](int) { return "int"; },
        [](auto) { return "unknown type"; },
    };

    std::cout << "TypeOfIntegral('h') = " << TypeOfIntegral('h') << std::endl;
    std::cout << "TypeOfIntegral(1) = " << TypeOfIntegral(1) << std::endl;
    std::cout << "TypeOfIntegral(1.1) = " << TypeOfIntegral(1.1) << std::endl;
    return 0;
}
