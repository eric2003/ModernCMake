#include <iostream>

int my_print()
{
	std::cout << " instanced!!! " << std::endl;
	return 0;
}

int main()
{
	auto func = [&]( auto val )
	{
		static int _ = my_print();
		std::cout << val << std::endl;
	};
	func(1);
	func(2);
	func(2.1);

	return 0;
}