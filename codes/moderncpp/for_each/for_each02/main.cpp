#include <algorithm>
#include <execution>
#include <iostream>
#include <vector>

int main() { 
  std::vector<std::string> v = { " Hello ", " Parallel STL! " };
  std::for_each(std::execution::par, v.begin(), v.end(),
    [](std::string& s) { std::cout << s << std::endl; }
  ); 
  return 0;
}