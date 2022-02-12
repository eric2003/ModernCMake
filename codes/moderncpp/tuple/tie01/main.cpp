// packing/unpacking tuples
#include <iostream>     // std::cout
#include <tuple>        // std::tuple, std::make_tuple, std::tie

int main ()
{
  int myint;
  char mychar;

  std::tuple<int,float,char> mytuple;

  mytuple = std::make_tuple (10, 2.6, 'a');          // packing values into tuple

  std::tie (myint, std::ignore, mychar) = mytuple;   // unpacking tuple into variables

  std::cout << "myint contains: " << myint << '\n';
  std::cout << "mychar contains: " << mychar << '\n';
  myint = 2022;
  mychar = 'b';
  std::cout << "myint now contains: " << myint << '\n';
  std::cout << "mychar now contains: " << mychar << '\n';  
  
  std::cout << "mytuple 0: " << std::get<0>(mytuple) << '\n';
  std::cout << "mytuple 1: " << std::get<1>(mytuple) << '\n';
  std::cout << "mytuple 2: " << std::get<2>(mytuple) << '\n';
  

  return 0;
}