#include <iostream>
#include <vector>

constexpr size_t n = 1<<20;

int main(int argc, char** argv)
{
    {
        std::cout << std::boolalpha;
        for ( int i = 0; i < 5; ++ i )
        {
            std::vector<int> arr(n);
            bool is_aligned = (uintptr_t)arr.data() % 16 == 0;
            std::cout << "std is_aligned(16): " << is_aligned << std::endl;
        }
    }
    {
        std::cout << std::boolalpha;
        for ( int i = 0; i < 5; ++ i )
        {
            std::vector<int> arr(n);
            bool is_aligned = (uintptr_t)arr.data() % 32 == 0;
            std::cout << "std is_aligned(32): " << is_aligned << std::endl;
        }
    }	
    {
        std::cout << std::boolalpha;
        for ( int i = 0; i < 5; ++ i )
        {
            std::vector<int> arr(n);
            bool is_aligned = (uintptr_t)arr.data() % 64 == 0;
            std::cout << "std is_aligned(64): " << is_aligned << std::endl;
        }
    }

    return 0;
}