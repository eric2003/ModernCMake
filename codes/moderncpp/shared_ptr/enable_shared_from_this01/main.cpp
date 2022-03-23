#include <memory>
#include <iostream>
 
struct Good : std::enable_shared_from_this<Good> // note: public inheritance
{
    std::shared_ptr<Good> getptr() {
        return shared_from_this();
    }
};

int main( int argc, char **argv )
{
    {
        // Good: the two shared_ptr's share the same object
        std::shared_ptr<Good> good0 = std::make_shared<Good>();
        std::shared_ptr<Good> good1 = good0->getptr();
        std::cout << "good0.use_count() = " << good0.use_count() << '\n';
        std::cout << "good1.use_count() = " << good1.use_count() << '\n';
    }

    return 0;
}
