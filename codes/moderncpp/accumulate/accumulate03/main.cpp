#include <iostream>
#include <vector>
#include <numeric>
 
int main( int argc, char **argv )
{
    std::vector<int> v{1, 2, 3, 4};
 
    int v1 = std::accumulate( v.begin(), v.end(), 0 );
    int v2 = std::accumulate( v.begin(), v.end(), 1, std::multiplies<int>() );
    int v3 = std::accumulate( v.begin(), v.end(), 1, std::multiplies<int>{} );
 
    std::cout << "v1: " << v1 << '\n';
    std::cout << "v2: " << v2 << '\n';
    std::cout << "v3: " << v3 << '\n';
    return 0;
}
