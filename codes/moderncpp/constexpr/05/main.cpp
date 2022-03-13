#include <iostream>
#include <variant>

int my_print()
{
	std::cout << " instanced!!! " << std::endl;
	return 0;
}

int main()
{
	std::variant<std::false_type, std::true_type> v;
	//v = std::false_type{};
	v = std::true_type{};
	std::visit(
		[&]( auto val )
		{
			static int _ = my_print();
			if constexpr ( val )
				std::cout << "my_true = " << val << std::endl;
			else
				std::cout << "my_false = " << val << std::endl;
		}, v
	);

	return 0;
}