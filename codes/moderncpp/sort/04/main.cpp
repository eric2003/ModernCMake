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

bool my_cmp_ptr(const data* a, const data* b)
{
    return a->word.size() < b->word.size();
}
 
int main( int argc, char **argv )
{
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
	}
	{
        std::vector < data * > pinfo;
        
        pinfo.push_back( new data{ "test", 4 } );
        pinfo.push_back( new data{ "a", 3 } );
        pinfo.push_back( new data{ "is", 2 } );
        pinfo.push_back( new data{ "this", 1 });
	    
        std::sort( pinfo.begin(), pinfo.end(), my_cmp_ptr );
	    
        for ( int i = 0; i < pinfo.size(); ++ i )
        {
            std::cout << (*pinfo[ i ]).word << " " << (*pinfo[ i ]).number << std::endl;
        }
        for ( int i = 0; i < pinfo.size(); ++ i )
        {
            delete pinfo[ i ];
        }		
	}	
 
    return 0;
}
