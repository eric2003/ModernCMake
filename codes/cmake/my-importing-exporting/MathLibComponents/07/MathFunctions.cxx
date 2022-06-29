#include "MathFunctions.h"

#include <cmath>
#include <iostream>

namespace MathFunctions {
double sqrt(double x)
{
  std::cout << "MathFunctions.cxx sqrt\n";
  return std::sqrt(x);
}
}
