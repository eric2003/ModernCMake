#include <memory>
#include <iostream>
 
struct C : std::enable_shared_from_this<C> { };

int main( int argc, char **argv )
{
    {
        std::shared_ptr<C> foo, bar;
        
        foo = std::make_shared<C>();
        
        bar = foo->shared_from_this();
        
        if ( !foo.owner_before(bar) && !bar.owner_before(foo) )
        {
            std::cout << "foo and bar share ownership"  << std::endl;
        }
    }

    return 0;
}
