#include <iostream>

template < typename T >
std::string cpp_type_name()
{
    const char *name = typeid(T).name();
    std::cout << "name = " << name << std::endl;
    std::string s = name;
    if( std::is_const_v< std::remove_reference_t<T> > )
    {
        s += " const";
    }
    if( std::is_volatile_v< std::remove_reference_t<T> > )
    {
        s += " volatile";
    }
    if( std::is_lvalue_reference_v< T > )
    {
        s += " &";
    }
    if( std::is_rvalue_reference_v< T > )
    {
        s += " &&";
    }
    return s;
}

int main( int argc, char **argv )
{
    std::cout << cpp_type_name<int>() << std::endl;
    std::cout << cpp_type_name<const int &>() << std::endl;

    return 0;
}
