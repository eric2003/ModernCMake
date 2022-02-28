#include <iostream>
#include <vector>
#include <numeric>
 
int main( int argc, char **argv )
{
    std::vector<int> v{1, 2, 3, 4};

    int v0 = std::reduce( v.begin(), v.end() );
    int v1 = std::reduce( v.begin(), v.end(), 0 );
    int v2 = std::reduce( v.begin(), v.end(), 0, std::minus<int>{} );
    int v3 = std::reduce( v.begin(), v.end(), 1, std::multiplies<int>{} );
 
    std::cout << "v0: " << v0 << '\n';
    std::cout << "v1: " << v1 << '\n';
    std::cout << "v2: " << v2 << '\n';
    std::cout << "v3: " << v3 << '\n';
    return 0;
}
