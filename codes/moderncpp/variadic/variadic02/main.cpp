#include <iostream>

#ifdef USE_MSVC
    #define FUNCTION_DETAIL __FUNCSIG__
#else
    #define FUNCTION_DETAIL __PRETTY_FUNCTION__
#endif

void print()
{
    std::cout << FUNCTION_DETAIL << ": " << std::endl;
}

template<typename T, typename... Args>
void print(T t, Args... args)
{
    std::cout << FUNCTION_DETAIL << ": " << t << std::endl;
    print(args...);
}


int main()
{
    print( 1, 2.5, 'a', 2022, "hello!");
    return 0;
}
