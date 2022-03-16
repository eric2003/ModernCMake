#include <iostream>
#include <vector>

int main( int argc, char **argv )
{
    std::vector<int> a = {1, 3, 2, 8, 5, 7};
    int tofind = 5;
    int index = [&] {
        for ( int i = 0; i < a.size(); ++ i )
            if ( a[i] == tofind )
                return i;
        return -1;
    }();
    std::cout << index << std::endl;

    return 0;
}
