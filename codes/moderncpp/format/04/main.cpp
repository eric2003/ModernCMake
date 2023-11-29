#include <format>
#include <iostream>
#include <fstream>

//https://madridccppug.github.io/posts/stdformat/

int main ( int argc, char **argv )
{
    {
        std::fstream file;
        file.open( "output.txt", std::ios_base::out );

        const std::string message = std::format("{1}, {0}!", "world", "hello");
        file << " message = " << message << "\n";
        file.close();
    }
    {
        std::cout << "\n\n";
        std::fstream file;
        file.open( "output1.txt", std::ios_base::out );
        std::format_to(std::ostream_iterator<char>(file), "hello, {}!", "world");
        file.close();
    }
    {
        std::cout << "\n\n";
        std::fstream file;
        file.open( "output2.txt", std::ios_base::out );
        std::format_to(std::ostream_iterator<char>(file), "hello, {}!", "world");
        std::format_to(std::ostream_iterator<char>(file), "hello, {}!", "world");
        file.close();
    }
    {
        std::cout << "\n\n";
        std::fstream file;
        file.open( "output3.txt", std::ios_base::out );
        std::format_to(std::ostream_iterator<char>(file), "hello, {}!\n", "world");
        std::format_to(std::ostream_iterator<char>(file), "hello, {}!", "world");
        file.close();
    }

    return 0;
}
