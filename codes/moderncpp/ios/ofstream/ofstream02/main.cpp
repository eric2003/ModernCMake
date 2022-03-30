#include <fstream>

int main( int argc, char **argv )
{
    {
        std::ofstream file ("test.txt");
        
        file << "hello world!";
        
        file.close();
    }

    return 0;
}
