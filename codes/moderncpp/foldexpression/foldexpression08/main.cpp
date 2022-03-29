#include <iostream>

void f( int i )
{
    std::cout << i << ' ';
}

bool pred(int i)
{
    //std::cout << std::boolalpha;
    //std::cout << "pred = " << (i == 2) << std::endl;
    return i == 2;
}

//Unary right fold (E op ...) becomes (E1 op (... op (EN-1 op EN)))
//(E , ...) becomes (E1 , (... , (EN-1 , EN)))
template <typename ... Ts>
void call(Ts... ts)
{
    ( f(ts), ...);
}

//Binary left fold (I op ... op E) becomes ((((I op E1) op E2) op ...) op EN)
template <typename ... Ts>
void reverse_call(Ts... ts)
{
    int dummy;
    (dummy = ... = ( f(ts), 0) );
}

//Unary right fold (E op ...) becomes (E1 op (... op (EN-1 op EN)))
//(E && ...) becomes (E1 && (... && (EN-1 && EN)))
template <typename ... Ts>
void my_and(Ts... ts)
{
    ((f(ts), true) && ...);
}

//Unary right fold (E op ...) becomes (E1 op (... op (EN-1 op EN)))
//(E || ...) becomes (E1 || (... || (EN-1 || EN)))
template <typename ... Ts>
bool any_of(Ts... ts)
{
    return (pred(ts) || ...);
}

//( init op ... op pack ) (4)
//4) binary left fold
//4) Binary left fold (I op ... op E) becomes ((((I op E1) op E2) op ...) op EN)
//(I + ... + E) becomes ((((I + E1) + E2) + ...) + EN)
template <typename ... Ts>
std::size_t count(Ts... ts)
{
    return (std::size_t(0) + ... + (pred(ts) ? 1 : 0));
}

template <typename ... Ts>
auto find(Ts... ts)
{
    std::common_type_t<decltype(ts)...> result;
    bool found = ((pred(ts) ? (result = ts, true) : false) || ...);
    return found ? result : -1;
}

template <typename ... Ts>
auto get(Ts... ts)
{
    std::size_t n = 1;

    std::common_type_t<decltype(ts)...> result;
    std::size_t i = 0;
    ((i++ == n ? (result = ts, true) : false) || ...);
    return result;
}

int main( int argc, char **argv )
{
    {
        std::cout << std::boolalpha;
        std::cout << get(1, 2, 3) << '\n';
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        std::cout << std::boolalpha;
        std::cout << get(2, 1, 2, 3) << '\n';
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        std::cout << std::boolalpha;
        std::cout << get(1, 10000, 2 ) << '\n';
        std::cout << std::endl;
        std::cout << std::endl;
    }
    return 0;
}
