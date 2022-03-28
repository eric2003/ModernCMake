#include <iostream>

void f( int i )
{
    std::cout << i << ' ';
}

//Binary left fold (I op ... op E) becomes ((((I op E1) op E2) op ...) op EN)
template <typename ... Ts>
void reverse_call(Ts... ts)
{
    int dummy;
    (dummy = ... = ( f(ts), 0) );
}

int main( int argc, char **argv )
{
    {
        std::cout << std::endl;
        int dummy = -1;
        ((( dummy = (f(1), 1) ) = (f(2), 2)) = (f(3), 3));
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        reverse_call( 1, 2, 3 );
        std::cout << std::endl;
        std::cout << std::endl;
    }
    return 0;
}
