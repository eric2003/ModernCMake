#include <iostream>

class red_t    {}; void red    (red_t    ) { }
class green_t  {}; void green  (green_t  ) { }
class blue_t   {}; void blue   (blue_t   ) { }

std::ostream& operator << (std::ostream& os, void(*)(red_t  )) { return (os << "red_t"  ); }
std::ostream& operator << (std::ostream& os, void(*)(green_t)) { return (os << "green_t"); }
std::ostream& operator << (std::ostream& os, void(*)(blue_t )) { return (os << "blue_t" ); }

int main( int argc, char **argv )
{
    std::cout << red << "\n";
    std::cout << green << "\n";
    std::cout << blue << "\n";
    return 0;
}
