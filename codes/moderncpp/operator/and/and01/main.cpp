#include <iostream>

bool bool_a()
{ 
    std::cout << "bool_a" << std::endl;
    return true;
}

bool bool_b()
{ 
    std::cout << "bool_b" << std::endl;
    return true;
}

bool bool_c()
{ 
    std::cout << "bool_c" << std::endl;
    return true;
}

int main(int argc, char** argv)
{
    bool result = false;
    result = ( bool_a() ) && ( bool_b() ) &&( bool_c() );
    std::cout << "result = " << std::boolalpha << result << std::endl;
    return 0;
}