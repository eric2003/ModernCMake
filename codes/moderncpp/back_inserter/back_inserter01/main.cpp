// back_inserter example
#include <iostream>     // std::cout
#include <iterator>     // std::back_inserter
#include <vector>       // std::vector
#include <algorithm>    // std::copy

int main ( int argc, char **argv )
{
    std::vector<int> foo, bar;
    for ( int i = 0; i< 5; ++ i )
    {
        foo.push_back(i);
        bar.push_back(i*10);
    }
    
    std::copy ( bar.begin(), bar.end(), back_inserter(foo) );
    
    std::cout << "foo contains:";
    for ( std::vector<int>::iterator it = foo.begin(); it!= foo.end(); ++ it )
    {
        std::cout << ' ' << *it;
    }
    std::cout << '\n';
    
    return 0;
}