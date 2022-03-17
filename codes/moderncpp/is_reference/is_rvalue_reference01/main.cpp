#include <iostream>
#include <type_traits>

class A {};

int main( int argc, char **argv )
{
    {
        //static_assert( std::is_rvalue_reference_v<A> );
        static_assert( not std::is_rvalue_reference_v<A> );
        static_assert( not std::is_rvalue_reference_v<A&> );
        static_assert(     std::is_rvalue_reference_v<A&&> );
        static_assert( not std::is_rvalue_reference_v<int> );
        static_assert( not std::is_rvalue_reference_v<int&> );
        static_assert(     std::is_rvalue_reference_v<int&&> );
    }

    return 0;
}
