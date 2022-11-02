#include <stacktrace>
#include <iostream>

int foo()
{
  std::cout << std::stacktrace::current();
  return {};
}

int main( int argc, char **argv )
{
    return foo();
}
