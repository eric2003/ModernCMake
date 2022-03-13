#include <iostream>
#include <variant>
#include <vector>

int my_print()
{
	std::cout << " instanced!!! " << std::endl;
	return 0;
}

void saxpy
(
	std::vector<float> a,
	float b,
	float c
)
{
	for ( auto &ai: a )
	{
		if ( b != 1 )
			ai *= b;
		if ( c != 0 )
			ai += c;
	}
}

int main()
{
	std::variant<std::false_type, std::true_type> v;
	//v = std::false_type{};
	//v = std::true_type{};
	//std::visit(
	//	[&]( auto val )
	//	{
	//		static int _ = my_print();
	//		if constexpr ( val )
	//			std::cout << "my_true = " << val << std::endl;
	//		else
	//			std::cout << "my_false = " << val << std::endl;
	//	}, v
	//);
	std::vector<float> a(1024);
	saxpy( a, 1, 0 );

	return 0;
}