#include <iostream>
#include <vector>
#include <numeric>

int my_add ( int x, int y ) { return x + 10 * y; }
int my_add_info ( int x, int y )
{
    std::cout << " my_add_info ...." << std::endl;
    std::cout << " x = " << x << "; y = " << y << "; x + 10 * y = " <<  x + 10 * y << std::endl;
    return x + 10 * y;
}
struct MyAddClass
{
    int operator()( int x, int y ) { return x + 10 * y; }
};
 
int main( int argc, char **argv )
{
    std::vector<int> v{1, 2, 3, 4};
    MyAddClass myAddClass{};
    int v0 = std::reduce( v.begin(), v.end() );
    int v1 = std::reduce( v.begin(), v.end(), 0 );
    int v2 = std::reduce( v.begin(), v.end(), 0, std::minus<int>{} );
    int v3 = std::reduce( v.begin(), v.end(), 1, std::multiplies<int>{} );
    int v4 = std::reduce( v.begin(), v.end(), 0, my_add );
    int v5 = std::reduce( v.begin(), v.end(), 0, MyAddClass{} );
    int v6 = std::reduce( v.begin(), v.end(), 0, myAddClass );

    std::cout << "v0: " << v0 << std::endl;
    std::cout << "v1: " << v1 << std::endl;
    std::cout << "v2: " << v2 << std::endl;
    std::cout << "v3: " << v3 << std::endl;
    std::cout << "v4: " << v4 << std::endl;
    std::cout << "v5: " << v5 << std::endl;
    std::cout << "v6: " << v6 << std::endl;

    int v7 = std::reduce( v.begin(), v.end(), 0, my_add_info );	
    std::cout << "v7: " << v7 << std::endl;

    return 0;
}
