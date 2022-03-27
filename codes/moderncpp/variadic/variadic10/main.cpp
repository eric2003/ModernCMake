#include <iostream>
#include <type_traits>

void f( int i )
{
    std::cout << i << ' ';
}

template <typename ... Ts>
void call(Ts... ts)
{
    (f(ts), ...);
}

template <typename ... Ts, typename G>
void Call(G g, Ts... ts)
{
    (g(ts), ...);
}


int main( int argc, char **argv )
{
    {
        call(1, 2, 3);
        std::cout << std::endl;
    }
    {
        Call(f, 1, 2, 3, 4);
        std::cout << std::endl;
    }
 
    return 0;
}
