#include <iostream>

// Demonstrates functionality of __FUNCTION__, __FUNCDNAME__, and __FUNCSIG__ macros
void exampleFunction()
{
    std::printf("Function name: %s\n", __FUNCTION__);
    std::printf("Decorated function name: %s\n", __FUNCDNAME__);
    std::printf("Function signature: %s\n", __FUNCSIG__);

    // Sample Output
    // -------------------------------------------------
    // Function name: exampleFunction
    // Decorated function name: ?exampleFunction@@YAXXZ
    // Function signature: void __cdecl exampleFunction(void)
}


int main( int argc, char **argv )
{
    exampleFunction();
    return 0;
}
