#include <iostream>
#include <variant>
#include <vector>

int my_print()
{
	std::cout << " instanced!!! " << std::endl;
	return 0;
}

std::variant<std::false_type, std::true_type>
bool_variant( bool x )
{
	if ( x )
		return std::true_type{};
	else
		return std::false_type{};
}

void saxpy
(
	std::vector<float> a,
	float b,
	float c
)
{
	auto has_b = bool_variant( b != 1 );
	auto has_c = bool_variant( c != 0 );
	std::visit( [&](auto has_b, auto has_c)
		{
			for ( auto &ai: a )
			{
				if constexpr ( has_b )
					ai *= b;
				if constexpr ( has_c )
					ai += c;
			}
		}, has_b, has_c );
}

int main()
{

	std::vector<float> a(1024);
	saxpy( a, 1, 0 );
	saxpy( a, 1, 3.14f );

	return 0;
}