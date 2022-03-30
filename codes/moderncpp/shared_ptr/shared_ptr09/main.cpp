#include <iostream>
#include <memory>

int main( int argc, char **argv )
{
    {
        int* p = new int (10);
        std::shared_ptr<int> a (p);
        
        if (a.get()==p)
          std::cout << "a and p point to the same location\n";
        
        // three ways of accessing the same address:
        std::cout << *a.get() << "\n";
        std::cout << *a << "\n";
        std::cout << *p << "\n";
    }
    {
        std::shared_ptr<int> foo = std::make_shared<int> (10);
        // same as:
        std::shared_ptr<int> bar (new int(10));

        std::cout << "*foo: " << *foo << '\n';
        std::cout << "*bar: " << *bar << '\n';
    }

    return 0;
}
