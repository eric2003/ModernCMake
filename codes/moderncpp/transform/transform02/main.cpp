// transform algorithm example
#include <iostream>     // std::cout
#include <algorithm>    // std::transform
#include <string>

char trans_char( char c )
{
    if ( std::islower( c ) )
    {
        return std::toupper( c );
    }
    else if ( std::isupper( c ) )
    {
        return std::tolower( c );
    }
    else
    {
        return c;
    }
}

class mytrans_char
{
public:
   char operator()(char c)
   {
       return trans_char(c);
   }
};

int main( int argc, char **argv )
{
    std::string mystr = {"abcd1234EFGH"};
    std::string mystr1 = mystr;
    std::string mystr2 = mystr;
    std::string mystr3 = {"abcdef1234EFGH"};
    std::cout << "mystr = " << mystr << std::endl;
    std::transform( mystr.begin(), mystr.end(), mystr.begin(), [](char c) -> char {
            if (std::islower(c))
              return std::toupper(c);
            else if (std::isupper(c))
              return std::tolower(c);
            else
              return c;
          });
    std::cout << "mystr new = " << mystr << std::endl;
    std::cout << "mystr1 = " << mystr1 << std::endl;
    std::transform( mystr1.begin(), mystr1.end(), mystr1.begin(), trans_char );
    std::cout << "mystr1 = " << mystr1 << std::endl;
    std::cout << "mystr2 = " << mystr2 << std::endl;
    std::transform( mystr2.begin(), mystr2.end(), mystr2.begin(), mytrans_char() );
    std::cout << "mystr2 = " << mystr2 << std::endl;
    std::cout << "mystr3 = " << mystr3 << std::endl;
    std::transform( mystr3.begin(), mystr3.end(), mystr3.begin(), mytrans_char{} );
    std::cout << "mystr3 = " << mystr3 << std::endl;

    return 0;
}
