#include <iostream>

struct [[nodiscard]] error_info { /*...*/ };
error_info enable_missile_safety_mode() { /*...*/ return {}; }
void launch_missiles() { /*...*/ }
void test_missiles()
{
   enable_missile_safety_mode(); // compiler may warn on discarding a nodiscard value
   launch_missiles();
}

// nodiscard( string-literal ) (since C++20):
struct [[nodiscard("OneFLOW CFD")]] cfd_info { /*...*/ };
void test_cfd()
{
   cfd_info();
}

int main ( int argc, char **argv )
{
    {
    }

    return 0;
}
