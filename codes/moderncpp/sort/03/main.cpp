#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct data
{
    std::string word;
    int number;

    bool operator<(const data& a) const
    {
        return word.size() < a.word.size();
    }
};
 
int main( int argc, char **argv )
{
    std::vector < data > info;
    
    info.push_back( data{ "test", 4 } );
    info.push_back( data{ "a", 3 } );
    info.push_back( data{ "is", 2 } );
    info.push_back( data{ "this", 1 });

    std::sort( info.begin(), info.end() );

    for ( int i = 0; i < info.size(); ++ i )
    {
        std::cout << info[ i ].word << " " << info[i].number << std::endl;
    }
 
    return 0;
}
