#include <iostream>
#include <vector>
#include <set>

int main( int argc, char **argv )
{
    std::vector<int> x = {1, 4, 2, 8, 5, 7, 1, 3, 4};
    std::set<int> visited;
    auto foo = [&] ( auto const &foo, int index ) -> void {
        std::cout << " current index = " << index << " current visited = ";
        for ( auto& v : visited )
        {
            std::cout << v << ' ';
        }
        std::cout << std::endl;
        if ( visited.find( index ) == visited.end() )
        {
            visited.insert( index );
            int next = x[ index ];
            std::cout << "index = " << index << " next = " << next << std::endl;
            foo( foo, next );
        }
        else
        {
            std::cout << "index = " << index << " in set<int> visited " << std::endl;
        }
    };
    foo( foo, 0 );

    return 0;
}
