#include <fstream>

int main( int argc, char **argv )
{
    {
        std::ofstream ofs ("test.txt", std::ofstream::out);
        
        ofs << "lorem ipsum";
        
        ofs.close();
    }

    return 0;
}
