// transform algorithm example
#include <iostream>     // std::cout
#include <algorithm>    // std::transform
#include <vector>       // std::vector
#include <functional>   // std::plus

int op_increase (int i) { return ++i; }

int main( int argc, char **argv )
{
    std::vector<int> foo;
    std::vector<int> bar;
    
    // set some values:
    for ( int i = 1; i < 6; ++ i )
    {
        foo.push_back (i*10);                         // foo: 10 20 30 40 50
    }
    
    bar.resize(foo.size());                         // allocate space
    
    std::transform ( foo.begin(), foo.end(), bar.begin(), op_increase );
                                                    // bar: 11 21 31 41 51
    std::cout << "bar = " << std::endl;
    for ( std::vector<int>::iterator it = bar.begin(); it != bar.end(); ++ it )
    {
        std::cout << ' ' << *it;    
    }
    std::cout << std::endl;
    // std::plus adds together its two arguments:
    std::transform (foo.begin(), foo.end(), bar.begin(), foo.begin(), std::plus<int>());
                                                    // foo: 21 41 61 81 101
    
    std::cout << "foo contains:";
    for ( std::vector<int>::iterator it = foo.begin(); it != foo.end(); ++ it )
    {
        std::cout << ' ' << *it;    
    }
    std::cout << std::endl;
    
    return 0;
}
