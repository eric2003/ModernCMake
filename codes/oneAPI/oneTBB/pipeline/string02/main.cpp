#include <cctype>
#include <fstream>
#include <iostream>
#include <memory>
#include <string>
#include <tbb/tick_count.h>
#include <tbb/parallel_pipeline.h>
#include <tbb/concurrent_queue.h>
#include <tbb/parallel_for.h>

void DumpString()
{
    std::string s;
    s.resize(200);
    int ascii_range = 'z' - 'A' + 2;
    std::size_t iz = 'z';
    std::size_t iA = 'A';
    std::cout << "ascii_range = " << ascii_range << std::endl;
    std::cout << "iz = " << iz << " iA = " << iA << std::endl;
    for ( int i = 0; i < s.size(); ++ i )
    {
        int offset = i % ascii_range;
        if ( offset )
        {
            s[ i ] = 'A' + offset - 1; 
        }
        else
        {
            //std::cout << " i= " << i << " end with " << s[ i-1 ] << std::endl;
            s[ i ] = '\n';
        }
    }
    std::cout << s << std::endl;
}

int main( int argc, char **argv )
{
    size_t n0 = 1 << 0;
    size_t n1 = 1 << 1;
    size_t n2 = 1 << 2;
    size_t n3 = 1 << 3;
    std::cout << " n0 = " << n0 << std::endl;
    std::cout << " n1 = " << n1 << std::endl;
    std::cout << " n2 = " << n2 << std::endl;
    std::cout << " n3 = " << n3 << std::endl;

    size_t n = 1 << 10;
    std::cout << " n  = " << n << std::endl;
    {
        double serial_time = 0.0;
        {
            tbb::tick_count t0 = tbb::tick_count::now();
            DumpString();
            serial_time = (tbb::tick_count::now() - t0).seconds();
        }
        std::cout << "serial_time == " << serial_time << " seconds" << std::endl;
    }

    return 0;
}

