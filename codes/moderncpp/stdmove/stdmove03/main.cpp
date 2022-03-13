#include <iostream>
#include <vector>

int main( int argc, char **argv )
{
    {
        std::vector<int> v1(10);
        std::vector<int> v2(200);

        v1 = v2;                  // O(n)

        std::cout << "after copy:" << std::endl;
        std::cout << "v1 length " << v1.size() << std::endl;  // 200
        std::cout << "v2 length " << v2.size() << std::endl;  // 200
    }
    {
        std::vector<int> v1(10);
        std::vector<int> v2(200);

        v1 = std::move(v2);      // O(1)

        std::cout << "after move:" << std::endl;
        std::cout << "v1 length " << v1.size() << std::endl;  // 200
        std::cout << "v2 length " << v2.size() << std::endl;  // 0
    }
    {
        std::vector<int> v1(10);
        std::vector<int> v2(200);

        std::swap(v1, v2);      // O(1)

        std::cout << "after swap:" << std::endl;
        std::cout << "v1 length " << v1.size() << std::endl;  // 200
        std::cout << "v2 length " << v2.size() << std::endl;  // 10
    }
    return 0;
}
