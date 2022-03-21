#include <iostream>
#include <string>
#include <vector>

template<typename T, typename... Args>
void myPushBack(std::vector<T>& v, Args&&... args) {
    (v.push_back(args), ...);                    // (1)
}

int main( int argc, char **argv )
{
    std::cout << '\n';

    std::vector<int> myIntVec;
    myPushBack(myIntVec, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
    for (auto v : myIntVec) std::cout << v << ' ';

    std::cout << "\n\n";

    std::vector myDoubleVec{1.1, 2.2, 3.3};      // (2)
    myPushBack(myDoubleVec, 4.4, 5.5, 6.6);
    for (auto v: myDoubleVec) std::cout << v << ' ';

    std::cout << "\n\n";

    return 0;
}
