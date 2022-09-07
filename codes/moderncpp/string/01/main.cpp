#include <iostream>
#include <string>
using namespace std;

#define R(...) string(" "#__VA_ARGS__" ") 
std::string opencl_c_container() {
    return R( // ########################## begin of OpenCL C code ####################################################################
        // ################################################## utility functions ##################################################

    ) + R( float sq( const float x ) {
        return x * x;
    }
    )+ R( float rq( const float x ) {
        return x * x;
    }) ;
}

#define F(...) string(" "#__VA_ARGS__" ") 
std::string my_c_container() {
    return F( // ########################## begin of OpenCL C code ####################################################################
        // ################################################## utility functions ##################################################

    ) + F( float sq( const float x ) {
        return x * x;
    }
    )+ F( float rq( const float x ) {
        return x * x;
    }) ;
}

#define G(...) string( "#__VA_ARGS__" ) 
std::string my_cc_container() {
    return G( // ########################## begin of OpenCL C code ####################################################################
        // ################################################## utility functions ##################################################

    ) + G( float sq( const float x ) {
        return x * x;
    }
    )+ G( float rq( const float x ) {
        return x * x;
    }) ;
}

int main( int argc, char **argv )
{
    std::cout << opencl_c_container() << "\n";
	std::cout << my_c_container() << "\n";
    std::cout << my_cc_container() << "\n";
    string c1 = string( " "" " );
    string c2 = string( "a""b" );
    string c3 = string( "a" "b" );
    string c4 = string( "a "" b" );
    string c5 = "a" "b";
    int kkk = 1;
    return 0;
}
