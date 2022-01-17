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
	func(std::integral_constant<int,1>());
	func(std::integral_constant<int,2>());
	func(std::integral_constant<int,3>());
	//func(1);
	//func(2);

	return 0;
}