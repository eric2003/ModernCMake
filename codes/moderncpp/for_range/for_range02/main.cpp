#include <iostream>
#include <vector>
#include <ranges>

int main( int argc, char **argv )
{
    {
        std::cout << "test1" << std::endl;
        std::vector<int> vec = {1, 2, 3, 4, 5};

        std::cout << "vec 0 = " << std::endl;
        for ( auto &&vi: vec )
        {
            std::cout << vi << ' ';
        }
        std::cout << std::endl;

        for ( int& i : vec )
        {
            i++; // increments the value in the vector
        }
        std::cout << "vec 1 = " << std::endl;
        for ( int i : vec )
        {
            // show that the values are updated
            std::cout << i << ' ';
        }
        std::cout << std::endl;
    }
    {
        std::cout << "test2" << std::endl;
        std::vector<int> vec = {1, 2, 3, 4, 5};

        std::cout << "vec 0 = " << std::endl;
        for ( auto &&vi: vec )
        {
            std::cout << vi << ' ';
        }
        std::cout << std::endl;

        for ( auto& vi : vec )
        {
            vi ++; // increments the value in the vector
        }
        std::cout << "vec 1 = " << std::endl;
        for ( auto vi : vec )
        {
            // show that the values are updated
            std::cout << vi << ' ';
        }
        std::cout << std::endl;
    }
    {
        std::cout << "test3" << std::endl;
        std::vector<int> vec = {1, 2, 3, 4, 5};

        std::cout << "vec 0 = " << std::endl;
        for ( auto &&vi: vec )
        {
            std::cout << vi << ' ';
        }
        std::cout << std::endl;

        std::cout << "vec 1 = " << std::endl;
        for ( int &vi: vec )
        {
            std::cout << vi << ' ';
        }
        std::cout << std::endl;

        std::cout << "vec 2 = " << std::endl;
        for ( int &vi: vec )
        {
            std::cout << ++ vi << ' ';
        }
        std::cout << std::endl;

        std::cout << "vec 3 = " << std::endl;
        for ( int vi: vec )
        {
            std::cout << vi << ' ';
        }
        std::cout << std::endl;
    }
    {
        std::cout << "test4" << std::endl;
        std::vector<int> vec =  {-2, -1, 0, 1, 2, 3, 4, 5 };

        std::cout << "vec 0 = " << std::endl;
        for ( auto &&vi: vec )
        {
            std::cout << vi << ' ';
        }
        std::cout << std::endl;

        std::cout << "vec 1 = " << std::endl;
        for ( int &vi: vec )
        {
            std::cout << vi << ' ';
        }
        std::cout << std::endl;

        std::cout << "vec 2 = " << std::endl;
        for ( int & vi : vec | std::views::filter([] (int &x) { return x >= 0; } ) )
        {
            //vi ++; // increments the value in the vector
            std::cout << vi << ' ';
        }
        std::cout << std::endl;

        std::cout << "vec 3 = " << std::endl;
        for ( auto vi : vec )
        {
            // show that the values are updated
            std::cout << vi << ' ';
        }
        std::cout << std::endl;
    }
    {
        std::cout << "test5" << std::endl;
        std::vector<int> vec =  {-2, -1, 0, 1, 2, 3, 4, 5 };

        std::cout << "vec 0 = " << std::endl;
        for ( auto &&vi: vec )
        {
            std::cout << vi << ' ';
        }
        std::cout << std::endl;

        std::cout << "vec 1 = " << std::endl;
        for ( int &vi: vec )
        {
            std::cout << vi << ' ';
        }
        std::cout << std::endl;

        std::cout << "vec 2 = " << std::endl;
        for ( int & vi : vec | std::views::filter([] (int &x) { return x >= 0; } ) )
        {
            vi += 10; // increments the value in the vector
            std::cout << vi << ' ';
        }
        std::cout << std::endl;

        std::cout << "vec 3 = " << std::endl;
        for ( auto vi : vec )
        {
            // show that the values are updated
            std::cout << vi << ' ';
        }
        std::cout << std::endl;
    }

    return 0;
}
