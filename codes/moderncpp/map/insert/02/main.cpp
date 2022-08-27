#include <iostream>
#include <map>

void Insert( std::map<int, int> &glbal_ptmap, int i0 )
{
    std::map<int, int>::iterator it = glbal_ptmap.find( i0 );
    if ( it == glbal_ptmap.end() )
    {
        glbal_ptmap.insert( std::pair<int,int>(i0,0) );
    }
    else
    {
        it->second ++;
    }
}

void Print( std::map<int, int> &glbal_ptmap, int i0 )
{
    std::cout << "print " << i0 << " => " << glbal_ptmap[i0] << '\n';
}
 
int main( int argc, char **argv )
{
    std::map<int,int> mymap;
    Insert( mymap, 0 );
    Insert( mymap, 100 );
    Insert( mymap, 100 );
    
    std::cout << "mymap contains:\n";
    for ( std::map<int,int>::iterator it = mymap.begin(); it != mymap.end(); ++ it )
    {
        std::cout << it->first << " => " << it->second << '\n';
    }

    Print( mymap, 0 );
    Print( mymap, 100 );
    Print( mymap, 101 );
    
    return 0;
}
