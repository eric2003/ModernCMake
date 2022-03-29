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


int main( int argc, char **argv )
{
    {
        std::cout << std::boolalpha;
        std::cout << count(1, 2, 3, 2) << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        std::cout << std::boolalpha;
        std::cout << count(1, 2, 3, 2, 2) << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
    }
    return 0;
}
