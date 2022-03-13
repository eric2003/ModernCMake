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
		if constexpr ( val )
			std::cout << "my_true = " << val << std::endl;
		else
			std::cout << "my_false = " << val << std::endl;
	};
	func(std::integral_constant<bool,true>());
	func(std::integral_constant<bool,false>());
	func(std::integral_constant<bool,false>());

	return 0;
}