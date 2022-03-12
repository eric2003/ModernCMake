#include <iostream>
#include <vector>

int main( int argc, char **argv )
{
    {
        std::cout << "test1" << std::endl;
        std::vector<int> vec = {1, 2, 3, 4, 5};

        std::cout << "vec 0 = " << std::endl;
        for (auto &&vi: vec)
        {
            std::cout << vi << ' ';
        }
        std::cout << std::endl;

        for ( int& i : vec )
        {
            i++; // increments the value in the vector
        }
        std::cout << "vec 1 = " << std::endl;
        for (int i : vec )
        {
            // show that the values are updated
            std::cout << i << ' ';
        }
        std::cout << std::endl;
    }

    return 0;
}
