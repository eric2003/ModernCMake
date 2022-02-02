#include <iostream>
#include <utility>
// whether foo is declared noexcept depends on if the expression
// T() will throw any exceptions
template <class T>
    void foo() noexcept(noexcept(T())) {}
 
void bar() noexcept(true) {}
void baz() noexcept { throw 42; } // noexcept is the same as noexcept(true)
 
int main() 
{
    std::cout << std::boolalpha << "noexcept(int())? " << noexcept( int() ) << std::endl;
    std::cout << std::boolalpha << "noexcept(0)? " << noexcept( 0 ) << std::endl;
	std::cout << std::boolalpha << "noexcept(1)? " << noexcept( 1 ) << std::endl;
	std::cout << std::boolalpha << "noexcept(true)? " << noexcept( true ) << std::endl;
	std::cout << std::boolalpha << "noexcept(false)? " << noexcept( false ) << std::endl;
    foo<int>(); // noexcept(noexcept(int())) => noexcept(true), so this is fine
 
    bar(); // fine
    //baz(); // compiles, but at runtime this calls std::terminate
    return 0;
}