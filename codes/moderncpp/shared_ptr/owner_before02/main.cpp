#include <iostream>
#include <memory>

int main( int argc, char **argv )
{
    {
        int * p = new int (10);
        
        std::shared_ptr<int> a (new int (20));
        std::shared_ptr<int> b (a,p);  // alias constructor
        
        std::cout << "comparing a and b...\n" << std::boolalpha;
        std::cout << "value-based: " << ( !(a<b) && !(b<a) ) << '\n';
        std::cout << "owner-based: " << ( !a.owner_before(b) && !b.owner_before(a) ) << '\n';
        
        delete p;
    }
    {
        int * p = new int (10);
        
        std::shared_ptr<int> a (new int (20));
        std::shared_ptr<int> b (a);
        
        std::cout << "comparing a and b...\n" << std::boolalpha;
        std::cout << "value-based: " << ( !(a<b) && !(b<a) ) << '\n';
        std::cout << "owner-based: " << ( !a.owner_before(b) && !b.owner_before(a) ) << '\n';
        
        delete p;
    }
    {
        int * p = new int (10);
        
        std::shared_ptr<int> a (new int (20));
        std::shared_ptr<int> b (a,p);  // alias constructor
        
        std::cout << "comparing a and b...\n" << std::boolalpha;
        std::cout << "a<b: " << ( a < b ) << std::endl;
        std::cout << "b<a: " << ( b < a ) << std::endl;
        std::cout << "a.owner_before(b): " << a.owner_before(b) << std::endl;
        std::cout << "b.owner_before(a): " << b.owner_before(a) << std::endl;
        
        delete p;
    }
    {
        int * p = new int (10);
        
        std::shared_ptr<int> a (new int (20));
        std::shared_ptr<int> b (a);  // alias constructor
        
        std::cout << "comparing a and b...\n" << std::boolalpha;
        std::cout << "a<b: " << ( a < b ) << std::endl;
        std::cout << "b<a: " << ( b < a ) << std::endl;
        std::cout << "a.owner_before(b): " << a.owner_before(b) << std::endl;
        std::cout << "b.owner_before(a): " << b.owner_before(a) << std::endl;
        
        delete p;
    }
    return 0;
}
