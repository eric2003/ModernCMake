#include <iostream>

template<typename Type>
std::string my_string_function()
{
    std::string fname(__FUNCSIG__);
    const char* to_str = "string_function<";
    size_t len = strlen(to_str);
    auto pos = fname.find("string_function<");
	
    std::printf("Function name: %s\n", __FUNCTION__);
    std::printf("Decorated function name: %s\n", __FUNCDNAME__);
    std::printf("Function signature: %s\n", __FUNCSIG__);

    //Function name: my_string_function
    //Decorated function name: ??$my_string_function@H@@YA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ
    //Function signature: class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > __cdecl my_string_function<int>(void)	
    return {""};
}

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
	my_string_function<int>();
    return 0;
}
