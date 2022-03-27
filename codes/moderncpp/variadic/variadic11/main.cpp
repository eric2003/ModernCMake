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

template <typename ... Ts>
void reverse_call(Ts... ts)
{
    int dummy;
    (dummy = ... = (f(ts), 0));
}

template <typename ... Ts, typename G>
void Call(G g, Ts... ts)
{
    (g(ts), ...);
}

template <typename ... Ts, typename G>
void ReverseCall(G g, Ts... ts)
{
    int dummy;
    (dummy = ... = (g(ts), 0));
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
    {
        reverse_call(1, 2, 3);
        std::cout << std::endl;
    }
    {
        ReverseCall(f, 1, 2, 3, 4);
        std::cout << std::endl;
    }
 
    return 0;
}
