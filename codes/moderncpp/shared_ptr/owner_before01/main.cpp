#include <iostream>
#include <memory>

int main( int argc, char **argv )
{
    int * p = new int (10);
    
    std::shared_ptr<int> a (new int (20));
    std::shared_ptr<int> b (a,p);  // alias constructor
    
    std::cout << "comparing a and b...\n" << std::boolalpha;
    std::cout << "value-based: " << ( !(a<b) && !(b<a) ) << '\n';
    std::cout << "owner-based: " << ( !a.owner_before(b) && !b.owner_before(a) ) << '\n';
    
    delete p;

    return 0;
}
