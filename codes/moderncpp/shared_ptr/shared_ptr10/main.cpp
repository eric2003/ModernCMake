#include <iostream>
#include <string>
#include <memory>

int main( int argc, char **argv )
{
    {
        std::shared_ptr<int> foo = std::make_shared<int> (10);
        // same as:
        std::shared_ptr<int> bar (new int(10));

        std::cout << "*foo: " << *foo << '\n';
        std::cout << "*bar: " << *bar << '\n';
    }
    {
        std::shared_ptr<std::string> foo = std::make_shared<std::string> ("hello world!");
        std::shared_ptr<std::string> bar(new std::string{"hello world!"});
        std::cout << "*foo: " << *foo << '\n';
        std::cout << "*bar: " << *bar << '\n';
    }

    return 0;
}
