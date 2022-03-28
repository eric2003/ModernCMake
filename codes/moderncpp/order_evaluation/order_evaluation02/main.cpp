#include <cstdio>
#include <iostream>
int a() { return std::puts("a"); }
int b() { return std::puts("b"); }
int c() { return std::puts("c"); }
void z(int, int, int) {}

int main( int argc, char **argv )
{
    {
        z(a(), b(), c());       // all 6 permutations of output are allowed
        int result = a() + b() + c(); // all 6 permutations of output are allowed
        ( a(), b(), c() );
    }
    return 0;
}
