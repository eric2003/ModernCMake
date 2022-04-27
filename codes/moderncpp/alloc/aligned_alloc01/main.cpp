#include <cstdio>
#include <cstdlib>

int main(int argc, char** argv)
{
    {
        int* p1 = static_cast<int*>(std::malloc(10*sizeof *p1));
        std::printf("default-aligned address:   %p\n", static_cast<void*>(p1));
        std::free(p1);
	    
        int* p2 = static_cast<int*>(std::aligned_alloc(1024, 1024));
        std::printf("1024-byte aligned address: %p\n", static_cast<void*>(p2));
        std::free(p2);
    }

    return 0;
}