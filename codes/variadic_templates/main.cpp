#include <iostream>

template<typename...T>
void f( T ... args )
{
	std::cout << sizeof ... ( args ) << std::endl;
}

int main()
{
	f();
	f(1);
	f(1, 2.3);
	return 0;
}
